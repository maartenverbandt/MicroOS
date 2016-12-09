// MESSAGE ROBOT_ID PACKING

#define MAVLINK_MSG_ID_ROBOT_ID 1

typedef struct __mavlink_robot_id_t
{
 uint8_t ID; ///< Field to set the new robot ID.
} mavlink_robot_id_t;

#define MAVLINK_MSG_ID_ROBOT_ID_LEN 1
#define MAVLINK_MSG_ID_1_LEN 1

#define MAVLINK_MSG_ID_ROBOT_ID_CRC 113
#define MAVLINK_MSG_ID_1_CRC 113



#define MAVLINK_MESSAGE_INFO_ROBOT_ID { \
	"ROBOT_ID", \
	1, \
	{  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_robot_id_t, ID) }, \
         } \
}


/**
 * @brief Pack a robot_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID Field to set the new robot ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t ID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ROBOT_ID_LEN];
	_mav_put_uint8_t(buf, 0, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#else
	mavlink_robot_id_t packet;
	packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ROBOT_ID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
}

/**
 * @brief Pack a robot_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID Field to set the new robot ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t ID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ROBOT_ID_LEN];
	_mav_put_uint8_t(buf, 0, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#else
	mavlink_robot_id_t packet;
	packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ROBOT_ID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
}

/**
 * @brief Encode a robot_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param robot_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_robot_id_t* robot_id)
{
	return mavlink_msg_robot_id_pack(system_id, component_id, msg, robot_id->ID);
}

/**
 * @brief Encode a robot_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param robot_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_robot_id_t* robot_id)
{
	return mavlink_msg_robot_id_pack_chan(system_id, component_id, chan, msg, robot_id->ID);
}

/**
 * @brief Send a robot_id message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Field to set the new robot ID.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_robot_id_send(mavlink_channel_t chan, uint8_t ID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ROBOT_ID_LEN];
	_mav_put_uint8_t(buf, 0, ID);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, buf, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, buf, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
#else
	mavlink_robot_id_t packet;
	packet.ID = ID;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, (const char *)&packet, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, (const char *)&packet, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_ROBOT_ID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_robot_id_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, ID);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, buf, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, buf, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
#else
	mavlink_robot_id_t *packet = (mavlink_robot_id_t *)msgbuf;
	packet->ID = ID;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, (const char *)packet, MAVLINK_MSG_ID_ROBOT_ID_LEN, MAVLINK_MSG_ID_ROBOT_ID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_ID, (const char *)packet, MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE ROBOT_ID UNPACKING


/**
 * @brief Get field ID from robot_id message
 *
 * @return Field to set the new robot ID.
 */
static inline uint8_t mavlink_msg_robot_id_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a robot_id message into a struct
 *
 * @param msg The message to decode
 * @param robot_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_robot_id_decode(const mavlink_message_t* msg, mavlink_robot_id_t* robot_id)
{
#if MAVLINK_NEED_BYTE_SWAP
	robot_id->ID = mavlink_msg_robot_id_get_ID(msg);
#else
	memcpy(robot_id, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ROBOT_ID_LEN);
#endif
}
