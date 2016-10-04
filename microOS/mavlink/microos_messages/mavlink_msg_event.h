// MESSAGE EVENT PACKING

#define MAVLINK_MSG_ID_EVENT 4

typedef struct __mavlink_event_t
{
 uint16_t type; ///< Event identifier. 0-1000 are reserved for microOS. User-specific events should be higher than 1000.
} mavlink_event_t;

#define MAVLINK_MSG_ID_EVENT_LEN 2
#define MAVLINK_MSG_ID_4_LEN 2

#define MAVLINK_MSG_ID_EVENT_CRC 133
#define MAVLINK_MSG_ID_4_CRC 133



#define MAVLINK_MESSAGE_INFO_EVENT { \
	"EVENT", \
	1, \
	{  { "type", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_event_t, type) }, \
         } \
}


/**
 * @brief Pack a event message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type Event identifier. 0-1000 are reserved for microOS. User-specific events should be higher than 1000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_event_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EVENT_LEN];
	_mav_put_uint16_t(buf, 0, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVENT_LEN);
#else
	mavlink_event_t packet;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVENT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EVENT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVENT_LEN);
#endif
}

/**
 * @brief Pack a event message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type Event identifier. 0-1000 are reserved for microOS. User-specific events should be higher than 1000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_event_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EVENT_LEN];
	_mav_put_uint16_t(buf, 0, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVENT_LEN);
#else
	mavlink_event_t packet;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVENT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EVENT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVENT_LEN);
#endif
}

/**
 * @brief Encode a event struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param event C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_event_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_event_t* event)
{
	return mavlink_msg_event_pack(system_id, component_id, msg, event->type);
}

/**
 * @brief Encode a event struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param event C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_event_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_event_t* event)
{
	return mavlink_msg_event_pack_chan(system_id, component_id, chan, msg, event->type);
}

/**
 * @brief Send a event message
 * @param chan MAVLink channel to send the message
 *
 * @param type Event identifier. 0-1000 are reserved for microOS. User-specific events should be higher than 1000.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_event_send(mavlink_channel_t chan, uint16_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EVENT_LEN];
	_mav_put_uint16_t(buf, 0, type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, buf, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, buf, MAVLINK_MSG_ID_EVENT_LEN);
#endif
#else
	mavlink_event_t packet;
	packet.type = type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, (const char *)&packet, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, (const char *)&packet, MAVLINK_MSG_ID_EVENT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_EVENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_event_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, buf, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, buf, MAVLINK_MSG_ID_EVENT_LEN);
#endif
#else
	mavlink_event_t *packet = (mavlink_event_t *)msgbuf;
	packet->type = type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, (const char *)packet, MAVLINK_MSG_ID_EVENT_LEN, MAVLINK_MSG_ID_EVENT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVENT, (const char *)packet, MAVLINK_MSG_ID_EVENT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE EVENT UNPACKING


/**
 * @brief Get field type from event message
 *
 * @return Event identifier. 0-1000 are reserved for microOS. User-specific events should be higher than 1000.
 */
static inline uint16_t mavlink_msg_event_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a event message into a struct
 *
 * @param msg The message to decode
 * @param event C-struct to decode the message contents into
 */
static inline void mavlink_msg_event_decode(const mavlink_message_t* msg, mavlink_event_t* event)
{
#if MAVLINK_NEED_BYTE_SWAP
	event->type = mavlink_msg_event_get_type(msg);
#else
	memcpy(event, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_EVENT_LEN);
#endif
}
