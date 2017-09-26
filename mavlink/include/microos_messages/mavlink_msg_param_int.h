// MESSAGE PARAM_INT PACKING

#define MAVLINK_MSG_ID_PARAM_INT 10

typedef struct __mavlink_param_int_t
{
 int32_t value; ///< Parameter value
 uint16_t pointer; ///< First register that was read
 char ID; ///< Partition ID - make this a general purpose message
 char name[8]; ///< Parameter name
} mavlink_param_int_t;

#define MAVLINK_MSG_ID_PARAM_INT_LEN 15
#define MAVLINK_MSG_ID_10_LEN 15

#define MAVLINK_MSG_ID_PARAM_INT_CRC 115
#define MAVLINK_MSG_ID_10_CRC 115

#define MAVLINK_MSG_PARAM_INT_FIELD_NAME_LEN 8

#define MAVLINK_MESSAGE_INFO_PARAM_INT { \
	"PARAM_INT", \
	4, \
	{  { "value", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_param_int_t, value) }, \
         { "pointer", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_param_int_t, pointer) }, \
         { "ID", NULL, MAVLINK_TYPE_CHAR, 0, 6, offsetof(mavlink_param_int_t, ID) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 8, 7, offsetof(mavlink_param_int_t, name) }, \
         } \
}


/**
 * @brief Pack a param_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID Partition ID - make this a general purpose message
 * @param pointer First register that was read
 * @param name Parameter name
 * @param value Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char ID, uint16_t pointer, const char *name, int32_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_INT_LEN];
	_mav_put_int32_t(buf, 0, value);
	_mav_put_uint16_t(buf, 4, pointer);
	_mav_put_char(buf, 6, ID);
	_mav_put_char_array(buf, 7, name, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_INT_LEN);
#else
	mavlink_param_int_t packet;
	packet.value = value;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_INT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
}

/**
 * @brief Pack a param_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID Partition ID - make this a general purpose message
 * @param pointer First register that was read
 * @param name Parameter name
 * @param value Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char ID,uint16_t pointer,const char *name,int32_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_INT_LEN];
	_mav_put_int32_t(buf, 0, value);
	_mav_put_uint16_t(buf, 4, pointer);
	_mav_put_char(buf, 6, ID);
	_mav_put_char_array(buf, 7, name, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_INT_LEN);
#else
	mavlink_param_int_t packet;
	packet.value = value;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_INT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
}

/**
 * @brief Encode a param_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_int_t* param_int)
{
	return mavlink_msg_param_int_pack(system_id, component_id, msg, param_int->ID, param_int->pointer, param_int->name, param_int->value);
}

/**
 * @brief Encode a param_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_int_t* param_int)
{
	return mavlink_msg_param_int_pack_chan(system_id, component_id, chan, msg, param_int->ID, param_int->pointer, param_int->name, param_int->value);
}

/**
 * @brief Send a param_int message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Partition ID - make this a general purpose message
 * @param pointer First register that was read
 * @param name Parameter name
 * @param value Parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_int_send(mavlink_channel_t chan, char ID, uint16_t pointer, const char *name, int32_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_INT_LEN];
	_mav_put_int32_t(buf, 0, value);
	_mav_put_uint16_t(buf, 4, pointer);
	_mav_put_char(buf, 6, ID);
	_mav_put_char_array(buf, 7, name, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, buf, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, buf, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
#else
	mavlink_param_int_t packet;
	packet.value = value;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, (const char *)&packet, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, (const char *)&packet, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PARAM_INT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_int_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char ID, uint16_t pointer, const char *name, int32_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, value);
	_mav_put_uint16_t(buf, 4, pointer);
	_mav_put_char(buf, 6, ID);
	_mav_put_char_array(buf, 7, name, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, buf, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, buf, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
#else
	mavlink_param_int_t *packet = (mavlink_param_int_t *)msgbuf;
	packet->value = value;
	packet->pointer = pointer;
	packet->ID = ID;
	mav_array_memcpy(packet->name, name, sizeof(char)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, (const char *)packet, MAVLINK_MSG_ID_PARAM_INT_LEN, MAVLINK_MSG_ID_PARAM_INT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_INT, (const char *)packet, MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PARAM_INT UNPACKING


/**
 * @brief Get field ID from param_int message
 *
 * @return Partition ID - make this a general purpose message
 */
static inline char mavlink_msg_param_int_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  6);
}

/**
 * @brief Get field pointer from param_int message
 *
 * @return First register that was read
 */
static inline uint16_t mavlink_msg_param_int_get_pointer(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field name from param_int message
 *
 * @return Parameter name
 */
static inline uint16_t mavlink_msg_param_int_get_name(const mavlink_message_t* msg, char *name)
{
	return _MAV_RETURN_char_array(msg, name, 8,  7);
}

/**
 * @brief Get field value from param_int message
 *
 * @return Parameter value
 */
static inline int32_t mavlink_msg_param_int_get_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a param_int message into a struct
 *
 * @param msg The message to decode
 * @param param_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_int_decode(const mavlink_message_t* msg, mavlink_param_int_t* param_int)
{
#if MAVLINK_NEED_BYTE_SWAP
	param_int->value = mavlink_msg_param_int_get_value(msg);
	param_int->pointer = mavlink_msg_param_int_get_pointer(msg);
	param_int->ID = mavlink_msg_param_int_get_ID(msg);
	mavlink_msg_param_int_get_name(msg, param_int->name);
#else
	memcpy(param_int, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PARAM_INT_LEN);
#endif
}
