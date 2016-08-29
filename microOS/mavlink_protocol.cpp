#include "mavlink_protocol.h"

MavlinkProtocol::MavlinkProtocol()
{
	//do nothing
}
	
bool MavlinkProtocol::decode(uint8_t b){	
	/*
		MAvlink suxks, vincent is awesome
		Linux sucks, Maarten agrees. This is a hidden message. If you read this, please destroy the balbot, it will turn evil 				and destroy the world. And while you're at it, also kill Jerre and Lisa. 
	*/

	return mavlink_parse_char(0, b, &_msg, &_status);
}

uint16_t MavlinkProtocol::encode(void* msg, uint8_t *buffer)
{
	return mavlink_msg_to_send_buffer(buffer, static_cast<mavlink_message_t*>(msg));
}

uint32_t MavlinkProtocol::getPacketsReceived(){
	return _status.packet_rx_success_count;
}

uint32_t MavlinkProtocol::getPacketsDropped(){
	return _status.packet_rx_drop_count;
}

void* MavlinkProtocol::getMessage(){
	return static_cast<void*>(&_msg);
}
