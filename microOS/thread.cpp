#include "thread.h"

Thread::Thread()
{
	//do nothing
}

Thread::Thread(priority_t priority, uint32_t period, int (*Fcn)(), char* name):
	_active(false),
	_ID(0),
	_priority(priority),
	_period(period),
	_scheduling_time(0),
	_duration(0),
	_latency(0),
	_total_duration(0),
	_total_latency(0),
	_number_of_executions(0),
	_pFcn(Fcn)
{
	memcpy(_name, name, THREAD_NAME_SIZE);
}

/*void Thread::operator=(const Thread t)
{
	_active = t._active;
	_ID = t._ID;
	
	_priority = t._priority;
	_period = t._period;
	_scheduling_time = t._scheduling_time;
	_execution_time = t._execution_time;
	
	_pFcn = t._pFcn;
}*/


bool Thread::startSequential()
{
	_active = true;
	_scheduling_time = micros();
	(*_pFcn)();
	return _active;
}

bool Thread::startRegular(uint32_t scheduling_time)
{
	_active = true;
	_scheduling_time = scheduling_time;
	return _active;
}

bool Thread::start()
{
	startSequential();
}

bool Thread::idle()
{
	_active = false;
	return _active;
}

bool Thread::action()
{
	if(_active){ // 
		uint32_t time = micros();
		uint32_t time_difference;
		if(_scheduling_time == 0){
			//set scheduling time
			_scheduling_time = time - _period;
			time_difference = _period;
		} else {
			//update scheduling time
			time_difference = time - _scheduling_time;
		}
		
		if(time_difference >= _period){
			// Execute scheduled task - first to create fewer variablility
			(*_pFcn)();
			_number_of_executions++;
			
			#ifdef AUTO_SCHEDULE_THREADING
			// Schedule next execution: this is done based on the last execution time so the thread is self-scheduling
			_scheduling_time = time;
			#else
			// Schedule next execution: this is done based on the period to have a fixed threading frequency
			_scheduling_time += _period;
			#endif
			
			// Calculate timing diagnostics
			_duration = micros() - time;
			_total_duration += _duration;
			_latency = time_difference - _period;
			_total_latency += _latency;
			
			return true;
		}
	}
	
	return false;
}

void Thread::setID(uint8_t ID)
{
    _ID = ID;
}

uint8_t Thread::getID()
{
	return _ID;
}

char* Thread::getName()
{
	return _name;
}

uint32_t Thread::getPeriod()
{
	return _period;
}

priority_t Thread::getPriority()
{
	return _priority;
} 

uint32_t Thread::getWakeupTime()
{
    return (_scheduling_time + _period);
}

uint32_t Thread::getDuration()
{
	return _duration;
}

uint32_t Thread::getLatency()
{
	return _latency;
}

uint32_t Thread::getTotalDuration()
{
	return _total_duration;
}

uint32_t Thread::getTotalLatency()
{
	return _total_latency;
}

uint32_t Thread::getNumberOfExecutions()
{
	return _number_of_executions;
}

uint32_t Thread::getAverageDuration()
{
	return _total_duration/_number_of_executions;
}

uint32_t Thread::getAverageLatency()
{
	return _total_latency/_number_of_executions;
}
