#include "mavlink_communicator.h"

MavlinkCommunicator::MavlinkCommunicator(const uint8_t id, HALBase *hal, const uint8_t type) :
	_id(id),
	_type(type),
	_channels({Channel(hal->getPrimarySerial(), new MavlinkProtocol),
			   Channel(hal->getSecondarySerial(), new MavlinkProtocol)})
{
	//do nothing
}

void MavlinkCommunicator::init()
{
	for(uint8_t k=0;k<2;k++){
		_channels[k].start();
	}
}

void MavlinkCommunicator::receive()
{
	for(uint8_t k=0;k<2;k++){
		while(_channels[k].receive()){
			System.print("Port "); System.print(k); System.print(": ");
			handleMessage(*reinterpret_cast<mavlink_message_t*>(_channels[k].getMessage()));
		}
	}
}

void MavlinkCommunicator::sendMessage(mavlink_message_t &msg)
{
	for(uint8_t k=0;k<2;k++){
		_channels[k].send(&msg);
	}
}

void MavlinkCommunicator::transmit()
{
	sendGPIO();
}

void MavlinkCommunicator::sendHeartbeat()
{
	mavlink_message_t msg;
	uint8_t data[8];
	mavlink_msg_heartbeat_pack(_id, 0, &msg, _type, millis(), data);

	sendMessage(msg);
}

void MavlinkCommunicator::sendThreadInfo(uint8_t ID, char* name, uint8_t priority, uint32_t duration, uint32_t latency, uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions)
{
	mavlink_message_t msg;
	mavlink_msg_thread_info_pack(_id, 0, &msg, millis(), ID, priority, duration, latency, total_duration, total_latency, number_of_executions);

	sendMessage(msg);
}

void MavlinkCommunicator::sendGPIO()
{
	mavlink_message_t msg;
	mavlink_msg_gpio_pack(_id, 0, &msg,  millis(), System.getGPoutFloat(), System.getGPoutInt());

	sendMessage(msg);
}

void MavlinkCommunicator::sendEvent(uint16_t event)
{
	mavlink_message_t msg;
	mavlink_msg_event_pack(_id, 0, &msg,  event);

	sendMessage(msg);
}

void MavlinkCommunicator::handleEvent(uint16_t event)
{
	//put some microOS related events here
	switch(event){
		case 1000:
			System.println("Button 1 pressed.");
			break;

		case 1001:
			System.println("Button 2 pressed.");
			break;

		case 1002:
			System.println("Button 3 pressed.");
			break;

		case 1003:
			System.println("Button 4 pressed.");
			break;
	}
}

void MavlinkCommunicator::sendPrint(const char *text)
{
	mavlink_message_t msg;
	mavlink_msg_print_pack(_id, 0, &msg, text);

	sendMessage(msg);
}

bool MavlinkCommunicator::handleMessage(mavlink_message_t &msg)
{
	System.println(msg.msgid);
	switch(msg.msgid){
		case MAVLINK_MSG_ID_GPIO:{
			mavlink_gpio_t gpio;
			mavlink_msg_gpio_decode(&msg,&gpio);

			memcpy(System.getGPinInt(),gpio.gpio_int,16); //4*4bytes
			memcpy(System.getGPinFloat(),gpio.gpio_float,32); //4*4bytes

			//System.println("Received gpio message.");
			break;}

		case MAVLINK_MSG_ID_EVENT:{
			mavlink_event_t event;
			mavlink_msg_event_decode(&msg,&event);

			handleEvent(event.type);
			//System.println("Received event message.");
			break;}

		/*case INTERESTING_MSG_ID:{
			//do something with the message
			break; }

		case LESS_INTERESTING_MSG_ID:{
			//do something with the message
			break; }*/

		default:
			return false;
	}

	return true;
}
