#ifndef MAVLINK_COMMUNICATOR_H
#define MAVLINK_COMMUNICATOR_H

#include "microOS.h"
#include "communicator_interface.h"
#include "channel.h"
#include "mavlink_protocol.h"

class MavlinkCommunicator : public CommunicatorInterface
{
protected:
	const uint8_t _id;
	const uint8_t _type;
	Channel _channels[2];

	virtual void sendMessage(mavlink_message_t &msg);
	virtual bool handleMessage(mavlink_message_t &msg);

public:
	MavlinkCommunicator(const uint8_t id, HALBase *hal, const uint8_t type = 0);

	virtual void init();
	virtual void receive();
	virtual void transmit();

	void sendHeartbeat();
	void sendThreadInfo(uint8_t ID, char* name, uint8_t priority,
						uint32_t duration, uint32_t latency,
						uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions);
	void sendGPIO();
	void sendEvent(uint16_t event);
	virtual void handleEvent(uint16_t event);
	void sendPrint(const char *text);
};

#endif //MAVLINK_COMMUNICATOR_H
