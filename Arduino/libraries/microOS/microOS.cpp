#include "microOS.h"

MicroOS System;

MicroOS::MicroOS():
#ifndef MICROOS_NOPRINT
	Print(),
#endif
	_system_info(NOINFO),
	_system_request(NOREQUEST),
#ifndef MICROOS_NOPRINT
	_print_buffer_head(0),
	_print_buffer_tail(0),
#endif
	_thread_count(0),
	_next_thread(0),
	_scheduled_thread(0),
	_config(0),
	_slowhook_splitcounter(0)
{
	int k;
	for(k=0;k<MICROOS_DEBUG_FLOAT_SIZE;k++){
		_gpin_float[k] = 0.0f;
		_gpout_float[k] = 0.0f;
	}
	for(k=0;k<MICROOS_DEBUG_INT_SIZE;k++){
		_gpin_int[k] = 0;
		_gpout_int[k] = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// MicroOS threads
///
////////////////////////////////////////////////////////////////////////////////////////

extern int slowhook_splitcounter = 0;
int microOSSlowLoop(void)
{
	switch(slowhook_splitcounter){
		case 0:
			System.hal()->onboardLedToggle();
			System.communicator()->sendHeartbeat();
			break;
		case 1:
			System.handleSystemRequest();
			break;
        case 2:
            System.sendNextThreadInfo();
            break;
            
		default:
#ifndef MICROOS_NOPRINT
			System.write();
#endif
			break;
	}

	if(++slowhook_splitcounter > 10)
		slowhook_splitcounter = 0;
	
	return 0;
}

int microOSFastLoop(void)
{
	System.communicator()->receive();
	System.communicator()->transmit();

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// MicroOS startup/run functions
///
////////////////////////////////////////////////////////////////////////////////////////

void MicroOS::setHAL(HALBase* hal)
{
	_hal = hal;
}

void MicroOS::setCommunicator(CommunicatorInterface* communicator)
{
	_communicator = communicator;
}

void MicroOS::configure(uint8_t config)
{
	_config = config;
}

void MicroOS::start(const start_t mode)
{
	// Fire up hal and communicator
	if(_hal==NULL)
		_hal = new HALBase();
	_hal->init();

	if(_communicator==NULL)
		_communicator = new MavlinkCommunicator(45,20,_hal);
	_communicator->init();

	// Add the different standard threads
	if((_config & MICROOS_SLOW_DISABLE) == 0)
		addThread(BELOWNORMAL, MICROOS_SLOW_THREAD_PERIOD, &microOSSlowLoop, false, MICROOS_SLOW_THREAD_ID);
	if((_config & MICROOS_FAST_DISABLE) == 0)
		addThread(NORMAL, MICROOS_FAST_THREAD_PERIOD, &microOSFastLoop, false, MICROOS_FAST_THREAD_ID);

	// Start the threading scheduler
	switch(mode){
		case SEQUENTIAL:
			for(uint8_t k=0;k<_thread_count;k++){
				_threads[k]->startSequential();
			}
			break;
		case REGULAR:{
			uint32_t interval, minimum_period, scheduling_time;
			for(uint8_t k=0;k<_thread_count;k++){
				if(_threads[k]->getPeriod() < minimum_period)
					minimum_period = _threads[k]->getPeriod();
			}
			interval = minimum_period/_thread_count;
			scheduling_time = micros();
			for(uint8_t k=0;k<_thread_count;k++){
				_threads[k]->startRegular(scheduling_time);
				scheduling_time += interval;
			}
		}
	}
}

void MicroOS::run(const system_run_t mode)
{
	switch(mode){
		case RESCHEDULED:{
			if(_threads[_scheduled_thread]->action()){
				for(uint8_t k=0;k<_thread_count;k++){
					if(_threads[_scheduled_thread]->getWakeupTime() > _threads[k]->getWakeupTime()){
						_scheduled_thread = k;
					}
				}
			}
			break;}

		case PRIORITIZED:
			for(uint8_t k=0;k<_thread_count;k++){
				if(_threads[k]->action()){
					break;
				}
			}
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// MicroOS HAL & Communicator getters
///
////////////////////////////////////////////////////////////////////////////////////////

HALBase* MicroOS::hal()
{
	return _hal;
}

CommunicatorInterface* MicroOS::communicator()
{
	return _communicator;
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// Part of the code related to threads
///
////////////////////////////////////////////////////////////////////////////////////////

int MicroOS::findThread(uint8_t ID)
{
	for(uint8_t k=0;k<_thread_count;k++){
		if(_threads[k]->getID()==ID){
			return k;
		}
	}

	return -1;
}


uint8_t MicroOS::addThread(priority_t priority, uint32_t period, int (*Fcn)(), bool start, uint8_t ID)
{
    Thread *thread = new Thread(priority, period, Fcn);
    thread->setID(ID);
    uint8_t newID = addThread(thread);

    if(start)
        thread->start();

    return newID;
}

uint8_t MicroOS::addThread(Thread *thread)
{
	uint8_t k = 0;
	bool IDtaken = false;

	// Check if the requested ID is still available
	if((thread->getID() == 0) || (findThread(thread->getID()) >= 0)){
		IDtaken = true;
	}

	// Search the list for an ID which has not yet been assigned
	while(IDtaken){
		thread->setID(thread->getID() + 1); 			//new search ID
		IDtaken = (findThread(thread->getID()) >= 0);	//test if it already exists
	}

	// Create new list of threads: one longer than before
	Thread **newThreads = new Thread*[_thread_count+1];

	// Add threads of higher priority first
	if(_thread_count > 0){
	    while((k < _thread_count) && (thread->getPriority() <= _threads[k]->getPriority())){
		    newThreads[k] = _threads[k];
		    k++;
	    }
	}

	// Add the new thread after all higher priority threads have taken their place
	newThreads[k] = thread;
	k++; _thread_count++;

	// Add all threads of lower priority
	while(k<_thread_count){
		newThreads[k] = _threads[k-1];
		k++;
	}

	// Delete the array with pointers to the threads and assign new array
	delete[] _threads;
	_threads = newThreads;

	// Debug: list current thread ids
	/*Serial.println("Current thread IDs..");
	for(k=0;k<_thread_count;k++){
	    Serial.println(_threads[k]->getID());
	}*/

	// Return the ID of the newly added thread
	return thread->getID();
}

Thread *MicroOS::thread(uint8_t ID)
{
	uint8_t k = findThread(ID);

	if(k>0)
		return _threads[k];
	else
		return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// Part of the code related to the system: requests, gpio, thread info, ...
///
////////////////////////////////////////////////////////////////////////////////////////

void MicroOS::sendSystemRequest(uint8_t system_request)
{
	_system_request = system_request;
}

void MicroOS::handleSystemRequest()
{
	switch(_system_request){
		case NOREQUEST: break;
		case THREADINFO:{
            sendAllThreadInfo();
			break;}
		case NEXTTHREADINFO:{
            sendNextThreadInfo();
			break;}
		case HWINFO:{
			//do nothing for now
			break;}
	}

	_system_request = NOREQUEST;
}

void MicroOS::sendNextThreadInfo(void)
{
    _communicator->sendThreadInfo(_threads[_next_thread]->getID(), _threads[_next_thread]->getPriority(), _threads[_next_thread]->getDuration(), _threads[_next_thread]->getLatency(), _threads[_next_thread]->getTotalDuration(), _threads[_next_thread]->getTotalLatency(), _threads[_next_thread]->getNumberOfExecutions());
	if(++_next_thread >= _thread_count)
				_next_thread = 0;
}

void MicroOS::sendAllThreadInfo(void)
{
	for(uint8_t k=0;k<_thread_count;k++)
		_communicator->sendThreadInfo(_threads[k]->getID(), _threads[k]->getPriority(), _threads[k]->getDuration(), _threads[k]->getLatency(), _threads[k]->getTotalDuration(), _threads[k]->getTotalLatency(), _threads[k]->getNumberOfExecutions());
}

float* MicroOS::getGPinFloat(void)
{
	return _gpin_float;
}

int32_t* MicroOS::getGPinInt(void)
{
	return _gpin_int;
}

float MicroOS::getGPinFloat(uint8_t index)
{
	if(index<MICROOS_DEBUG_FLOAT_SIZE){
		return _gpin_float[index];
	} else {
		return 0.0f;
	}
}

int32_t MicroOS::getGPinInt(uint8_t index)
{
	if(index<MICROOS_DEBUG_INT_SIZE){
		return _gpin_int[index];
	} else {
		return 0;
	}
}

void MicroOS::setGPinFloat(uint8_t index, float value)
{
	if(index<MICROOS_DEBUG_FLOAT_SIZE){
		_gpin_float[index] = value;
	}
}

void MicroOS::setGPinInt(uint8_t index, int32_t value)
{
	if(index<MICROOS_DEBUG_INT_SIZE){
		_gpin_int[index] = value;
	}
}

float* MicroOS::getGPoutFloat(void)
{
	return _gpout_float;
}

int32_t* MicroOS::getGPoutInt(void)
{
	return _gpout_int;
}

float MicroOS::getGPoutFloat(uint8_t index)
{
	if(index<MICROOS_DEBUG_FLOAT_SIZE){
		return _gpout_float[index];
	} else {
		return 0.0f;
	}
}

int32_t MicroOS::getGPoutInt(uint8_t index)
{
	if(index<MICROOS_DEBUG_INT_SIZE){
		return _gpout_int[index];
	} else {
		return 0;
	}
}

void MicroOS::setGPoutFloat(uint8_t index, float value)
{
	if(index<MICROOS_DEBUG_FLOAT_SIZE){
		_gpout_float[index] = value;
	}
}

void MicroOS::setGPoutInt(uint8_t index, int32_t value)
{
	if(index<MICROOS_DEBUG_INT_SIZE){
		_gpout_int[index] = value;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
///
/// Part of the code related to print service of the MicroOS
///
////////////////////////////////////////////////////////////////////////////////////////

#ifndef MICROOS_NOPRINT
void MicroOS::write()
{
	if(_print_buffer_tail!=0){
		_communicator->sendPrint(_print_buffer + _print_buffer_head);
		memset(_print_buffer + _print_buffer_head,0,32); //erase the 32 bytes
		_print_buffer_head += 32; //communicator reads 32 bytes at a time
		if(_print_buffer_head >= _print_buffer_tail){
			_print_buffer_head = 0;
			_print_buffer_tail = 0;
		}
	}
}

size_t MicroOS::write(const uint8_t c)
{
	if(_print_buffer_tail<MICROOS_PRINT_BUFFER_SIZE){
		_print_buffer[_print_buffer_tail] = c;
		_print_buffer_tail++;
		return 1;
	}
	return 0;
}

size_t MicroOS::write(const uint8_t *buffer, size_t size)
{
	//check if the string fits in the provided buffer
	size = min(MICROOS_PRINT_BUFFER_SIZE-_print_buffer_tail,size);

	//copy the buffer to the _print_buffer beginning
	memcpy(_print_buffer + _print_buffer_tail, buffer, size);
	_print_buffer_tail += size;

	return size;
}
#else
void MicroOS::println(const char *text)
{
	_communicator->sendPrint(text);
}

/*#ifndef PGM_P
#define PGM_P const char *
#endif*/

void MicroOS::println(const __FlashStringHelper *text)
{
	PGM_P p = reinterpret_cast<PGM_P>(text);
	size_t n = 0;
	char buffer[MICROOS_PRINT_BUFFER_SIZE];
	while(n < MICROOS_PRINT_BUFFER_SIZE){
		buffer[n] = pgm_read_byte(p++);
		if (buffer[n] == 0) break;
		n++;
	}
	println(buffer);
	//return n;
}
#endif
