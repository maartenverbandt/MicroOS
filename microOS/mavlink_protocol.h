#ifndef MAVLINK_PROTOCOL_H
#define MAVLINK_PROTOCOL_H

#include "protocol_interface.h"
#include "mavlink.h"

class MavlinkProtocol : public ProtocolInterface
{
private:
	mavlink_message_t	_msg;
	mavlink_status_t	_status;

public:
	MavlinkProtocol();
	
	bool decode(uint8_t b);
	uint16_t encode(void* msg, uint8_t *buffer);
	
	uint32_t getPacketsReceived();
	uint32_t getPacketsDropped();
	
	void* getMessage();
};

#endif //MAVLINK_PROTOCOL_H
