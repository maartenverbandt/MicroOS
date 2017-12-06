// MESSAGE PARAM_STRING PACKING

#define MAVLINK_MSG_ID_PARAM_STRING 12

typedef struct __mavlink_param_string_t
{
 uint16_t pointer; ///< First register that was read
 char ID; ///< Partition ID - make this a general purpose message
 char name[8]; ///< Parameter name
 char value[32]; ///< Parameter value
} mavlink_param_string_t;

#define MAVLINK_MSG_ID_PARAM_STRING_LEN 43
#define MAVLINK_MSG_ID_12_LEN 43

#define MAVLINK_MSG_ID_PARAM_STRING_CRC 251
#define MAVLINK_MSG_ID_12_CRC 251

#define MAVLINK_MSG_PARAM_STRING_FIELD_NAME_LEN 8
#define MAVLINK_MSG_PARAM_STRING_FIELD_VALUE_LEN 32

#define MAVLINK_MESSAGE_INFO_PARAM_STRING { \
	"PARAM_STRING", \
	4, \
	{  { "pointer", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_param_string_t, pointer) }, \
         { "ID", NULL, MAVLINK_TYPE_CHAR, 0, 2, offsetof(mavlink_param_string_t, ID) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 8, 3, offsetof(mavlink_param_string_t, name) }, \
         { "value", NULL, MAVLINK_TYPE_CHAR, 32, 11, offsetof(mavlink_param_string_t, value) }, \
         } \
}


/**
 * @brief Pack a param_string message
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
static inline uint16_t mavlink_msg_param_string_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char ID, uint16_t pointer, const char *name, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_STRING_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_char_array(buf, 11, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#else
	mavlink_param_string_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_STRING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
}

/**
 * @brief Pack a param_string message on a channel
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
static inline uint16_t mavlink_msg_param_string_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char ID,uint16_t pointer,const char *name,const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_STRING_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_char_array(buf, 11, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#else
	mavlink_param_string_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_STRING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
}

/**
 * @brief Encode a param_string struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_string C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_string_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_string_t* param_string)
{
	return mavlink_msg_param_string_pack(system_id, component_id, msg, param_string->ID, param_string->pointer, param_string->name, param_string->value);
}

/**
 * @brief Encode a param_string struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_string C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_string_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_string_t* param_string)
{
	return mavlink_msg_param_string_pack_chan(system_id, component_id, chan, msg, param_string->ID, param_string->pointer, param_string->name, param_string->value);
}

/**
 * @brief Send a param_string message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Partition ID - make this a general purpose message
 * @param pointer First register that was read
 * @param name Parameter name
 * @param value Parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_string_send(mavlink_channel_t chan, char ID, uint16_t pointer, const char *name, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_STRING_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_char_array(buf, 11, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, buf, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, buf, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
#else
	mavlink_param_string_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, (const char *)&packet, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, (const char *)&packet, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PARAM_STRING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_string_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char ID, uint16_t pointer, const char *name, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_char_array(buf, 11, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, buf, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, buf, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
#else
	mavlink_param_string_t *packet = (mavlink_param_string_t *)msgbuf;
	packet->pointer = pointer;
	packet->ID = ID;
	mav_array_memcpy(packet->name, name, sizeof(char)*8);
	mav_array_memcpy(packet->value, value, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, (const char *)packet, MAVLINK_MSG_ID_PARAM_STRING_LEN, MAVLINK_MSG_ID_PARAM_STRING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_STRING, (const char *)packet, MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PARAM_STRING UNPACKING


/**
 * @brief Get field ID from param_string message
 *
 * @return Partition ID - make this a general purpose message
 */
static inline char mavlink_msg_param_string_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  2);
}

/**
 * @brief Get field pointer from param_string message
 *
 * @return First register that was read
 */
static inline uint16_t mavlink_msg_param_string_get_pointer(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field name from param_string message
 *
 * @return Parameter name
 */
static inline uint16_t mavlink_msg_param_string_get_name(const mavlink_message_t* msg, char *name)
{
	return _MAV_RETURN_char_array(msg, name, 8,  3);
}

/**
 * @brief Get field value from param_string message
 *
 * @return Parameter value
 */
static inline uint16_t mavlink_msg_param_string_get_value(const mavlink_message_t* msg, char *value)
{
	return _MAV_RETURN_char_array(msg, value, 32,  11);
}

/**
 * @brief Decode a param_string message into a struct
 *
 * @param msg The message to decode
 * @param param_string C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_string_decode(const mavlink_message_t* msg, mavlink_param_string_t* param_string)
{
#if MAVLINK_NEED_BYTE_SWAP
	param_string->pointer = mavlink_msg_param_string_get_pointer(msg);
	param_string->ID = mavlink_msg_param_string_get_ID(msg);
	mavlink_msg_param_string_get_name(msg, param_string->name);
	mavlink_msg_param_string_get_value(msg, param_string->value);
#else
	memcpy(param_string, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PARAM_STRING_LEN);
#endif
}
