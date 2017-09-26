// MESSAGE PARAM_DATA PACKING

#define MAVLINK_MSG_ID_PARAM_DATA 13

typedef struct __mavlink_param_data_t
{
 uint16_t pointer; ///< First register that was read
 char ID; ///< Partition ID - make this a general purpose message
 char name[8]; ///< Parameter name
 uint8_t value[32]; ///< Parameter value
} mavlink_param_data_t;

#define MAVLINK_MSG_ID_PARAM_DATA_LEN 43
#define MAVLINK_MSG_ID_13_LEN 43

#define MAVLINK_MSG_ID_PARAM_DATA_CRC 24
#define MAVLINK_MSG_ID_13_CRC 24

#define MAVLINK_MSG_PARAM_DATA_FIELD_NAME_LEN 8
#define MAVLINK_MSG_PARAM_DATA_FIELD_VALUE_LEN 32

#define MAVLINK_MESSAGE_INFO_PARAM_DATA { \
	"PARAM_DATA", \
	4, \
	{  { "pointer", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_param_data_t, pointer) }, \
         { "ID", NULL, MAVLINK_TYPE_CHAR, 0, 2, offsetof(mavlink_param_data_t, ID) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 8, 3, offsetof(mavlink_param_data_t, name) }, \
         { "value", NULL, MAVLINK_TYPE_UINT8_T, 32, 11, offsetof(mavlink_param_data_t, value) }, \
         } \
}


/**
 * @brief Pack a param_data message
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
static inline uint16_t mavlink_msg_param_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char ID, uint16_t pointer, const char *name, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_DATA_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_uint8_t_array(buf, 11, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#else
	mavlink_param_data_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
}

/**
 * @brief Pack a param_data message on a channel
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
static inline uint16_t mavlink_msg_param_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char ID,uint16_t pointer,const char *name,const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_DATA_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_uint8_t_array(buf, 11, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#else
	mavlink_param_data_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARAM_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
}

/**
 * @brief Encode a param_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_data_t* param_data)
{
	return mavlink_msg_param_data_pack(system_id, component_id, msg, param_data->ID, param_data->pointer, param_data->name, param_data->value);
}

/**
 * @brief Encode a param_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_data_t* param_data)
{
	return mavlink_msg_param_data_pack_chan(system_id, component_id, chan, msg, param_data->ID, param_data->pointer, param_data->name, param_data->value);
}

/**
 * @brief Send a param_data message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Partition ID - make this a general purpose message
 * @param pointer First register that was read
 * @param name Parameter name
 * @param value Parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_data_send(mavlink_channel_t chan, char ID, uint16_t pointer, const char *name, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARAM_DATA_LEN];
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_uint8_t_array(buf, 11, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, buf, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, buf, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
#else
	mavlink_param_data_t packet;
	packet.pointer = pointer;
	packet.ID = ID;
	mav_array_memcpy(packet.name, name, sizeof(char)*8);
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, (const char *)&packet, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, (const char *)&packet, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PARAM_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char ID, uint16_t pointer, const char *name, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, pointer);
	_mav_put_char(buf, 2, ID);
	_mav_put_char_array(buf, 3, name, 8);
	_mav_put_uint8_t_array(buf, 11, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, buf, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, buf, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
#else
	mavlink_param_data_t *packet = (mavlink_param_data_t *)msgbuf;
	packet->pointer = pointer;
	packet->ID = ID;
	mav_array_memcpy(packet->name, name, sizeof(char)*8);
	mav_array_memcpy(packet->value, value, sizeof(uint8_t)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, (const char *)packet, MAVLINK_MSG_ID_PARAM_DATA_LEN, MAVLINK_MSG_ID_PARAM_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_DATA, (const char *)packet, MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PARAM_DATA UNPACKING


/**
 * @brief Get field ID from param_data message
 *
 * @return Partition ID - make this a general purpose message
 */
static inline char mavlink_msg_param_data_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  2);
}

/**
 * @brief Get field pointer from param_data message
 *
 * @return First register that was read
 */
static inline uint16_t mavlink_msg_param_data_get_pointer(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field name from param_data message
 *
 * @return Parameter name
 */
static inline uint16_t mavlink_msg_param_data_get_name(const mavlink_message_t* msg, char *name)
{
	return _MAV_RETURN_char_array(msg, name, 8,  3);
}

/**
 * @brief Get field value from param_data message
 *
 * @return Parameter value
 */
static inline uint16_t mavlink_msg_param_data_get_value(const mavlink_message_t* msg, uint8_t *value)
{
	return _MAV_RETURN_uint8_t_array(msg, value, 32,  11);
}

/**
 * @brief Decode a param_data message into a struct
 *
 * @param msg The message to decode
 * @param param_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_data_decode(const mavlink_message_t* msg, mavlink_param_data_t* param_data)
{
#if MAVLINK_NEED_BYTE_SWAP
	param_data->pointer = mavlink_msg_param_data_get_pointer(msg);
	param_data->ID = mavlink_msg_param_data_get_ID(msg);
	mavlink_msg_param_data_get_name(msg, param_data->name);
	mavlink_msg_param_data_get_value(msg, param_data->value);
#else
	memcpy(param_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PARAM_DATA_LEN);
#endif
}
