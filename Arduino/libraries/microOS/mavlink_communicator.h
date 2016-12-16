#ifndef MAVLINK_COMMUNICATOR_H
#define MAVLINK_COMMUNICATOR_H

#include "microOS.h"
#include "communicator_interface.h"
#include "channel.h"
#include "mavlink_protocol.h"

#if defined(__AVR_ATmega328P__)
	#define SINGLE_CHANNEL
	#define NUMBER_OF_CHANNELS	1
#else
	#define MULTI_CHANNEL
	#define NUMBER_OF_CHANNELS	2	
#endif

class MavlinkCommunicator : public CommunicatorInterface
{
protected:
	HALBase *_hal;
	const uint8_t _id;
	const uint8_t _type;
	Channel _channels[NUMBER_OF_CHANNELS];

	virtual void sendMessage(mavlink_message_t &msg);
	virtual bool handleMessage(mavlink_message_t &msg);

	virtual void handleEvent(uint16_t event);
	virtual void handlePartition(const mavlink_partition_t &partition);
	
public:
	MavlinkCommunicator(const uint8_t id, const uint8_t type, HALBase *hal);

	virtual void init();
	virtual void receive();
	virtual void transmit();

	void sendHeartbeat();
	void sendThreadInfo(uint8_t ID, uint8_t priority,
						uint32_t duration, uint32_t latency, 
						uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions);
	void sendGPIO();
	void sendEvent(uint16_t event);
	void sendPrint(const char *text);
};

#endif //MAVLINK_COMMUNICATOR_H
