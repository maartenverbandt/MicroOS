// MESSAGE PARTITION PACKING

#define MAVLINK_MSG_ID_PARTITION 2

typedef struct __mavlink_partition_t
{
 uint16_t index; ///< First register that was read out.
 char ID; ///< Partition ID - make this a general purpose message
 uint8_t size; ///< Holds how many bytes are of importance, begining from index.
 uint8_t togo; ///< Holds how many partitions are still to come. If togo = 0, the last message was received.
 uint8_t value[32]; ///< Values of the 32 fields, starting from the indicated register
} mavlink_partition_t;

#define MAVLINK_MSG_ID_PARTITION_LEN 37
#define MAVLINK_MSG_ID_2_LEN 37

#define MAVLINK_MSG_ID_PARTITION_CRC 248
#define MAVLINK_MSG_ID_2_CRC 248

#define MAVLINK_MSG_PARTITION_FIELD_VALUE_LEN 32

#define MAVLINK_MESSAGE_INFO_PARTITION { \
	"PARTITION", \
	5, \
	{  { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_partition_t, index) }, \
         { "ID", NULL, MAVLINK_TYPE_CHAR, 0, 2, offsetof(mavlink_partition_t, ID) }, \
         { "size", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_partition_t, size) }, \
         { "togo", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_partition_t, togo) }, \
         { "value", NULL, MAVLINK_TYPE_UINT8_T, 32, 5, offsetof(mavlink_partition_t, value) }, \
         } \
}


/**
 * @brief Pack a partition message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID Partition ID - make this a general purpose message
 * @param index First register that was read out.
 * @param size Holds how many bytes are of importance, begining from index.
 * @param togo Holds how many partitions are still to come. If togo = 0, the last message was received.
 * @param value Values of the 32 fields, starting from the indicated register
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_partition_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char ID, uint16_t index, uint8_t size, uint8_t togo, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARTITION_LEN];
	_mav_put_uint16_t(buf, 0, index);
	_mav_put_char(buf, 2, ID);
	_mav_put_uint8_t(buf, 3, size);
	_mav_put_uint8_t(buf, 4, togo);
	_mav_put_uint8_t_array(buf, 5, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARTITION_LEN);
#else
	mavlink_partition_t packet;
	packet.index = index;
	packet.ID = ID;
	packet.size = size;
	packet.togo = togo;
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARTITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARTITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
}

/**
 * @brief Pack a partition message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID Partition ID - make this a general purpose message
 * @param index First register that was read out.
 * @param size Holds how many bytes are of importance, begining from index.
 * @param togo Holds how many partitions are still to come. If togo = 0, the last message was received.
 * @param value Values of the 32 fields, starting from the indicated register
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_partition_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char ID,uint16_t index,uint8_t size,uint8_t togo,const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARTITION_LEN];
	_mav_put_uint16_t(buf, 0, index);
	_mav_put_char(buf, 2, ID);
	_mav_put_uint8_t(buf, 3, size);
	_mav_put_uint8_t(buf, 4, togo);
	_mav_put_uint8_t_array(buf, 5, value, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARTITION_LEN);
#else
	mavlink_partition_t packet;
	packet.index = index;
	packet.ID = ID;
	packet.size = size;
	packet.togo = togo;
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARTITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PARTITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
}

/**
 * @brief Encode a partition struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param partition C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_partition_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_partition_t* partition)
{
	return mavlink_msg_partition_pack(system_id, component_id, msg, partition->ID, partition->index, partition->size, partition->togo, partition->value);
}

/**
 * @brief Encode a partition struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param partition C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_partition_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_partition_t* partition)
{
	return mavlink_msg_partition_pack_chan(system_id, component_id, chan, msg, partition->ID, partition->index, partition->size, partition->togo, partition->value);
}

/**
 * @brief Send a partition message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Partition ID - make this a general purpose message
 * @param index First register that was read out.
 * @param size Holds how many bytes are of importance, begining from index.
 * @param togo Holds how many partitions are still to come. If togo = 0, the last message was received.
 * @param value Values of the 32 fields, starting from the indicated register
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_partition_send(mavlink_channel_t chan, char ID, uint16_t index, uint8_t size, uint8_t togo, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PARTITION_LEN];
	_mav_put_uint16_t(buf, 0, index);
	_mav_put_char(buf, 2, ID);
	_mav_put_uint8_t(buf, 3, size);
	_mav_put_uint8_t(buf, 4, togo);
	_mav_put_uint8_t_array(buf, 5, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, buf, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, buf, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
#else
	mavlink_partition_t packet;
	packet.index = index;
	packet.ID = ID;
	packet.size = size;
	packet.togo = togo;
	mav_array_memcpy(packet.value, value, sizeof(uint8_t)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, (const char *)&packet, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, (const char *)&packet, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PARTITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_partition_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char ID, uint16_t index, uint8_t size, uint8_t togo, const uint8_t *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, index);
	_mav_put_char(buf, 2, ID);
	_mav_put_uint8_t(buf, 3, size);
	_mav_put_uint8_t(buf, 4, togo);
	_mav_put_uint8_t_array(buf, 5, value, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, buf, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, buf, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
#else
	mavlink_partition_t *packet = (mavlink_partition_t *)msgbuf;
	packet->index = index;
	packet->ID = ID;
	packet->size = size;
	packet->togo = togo;
	mav_array_memcpy(packet->value, value, sizeof(uint8_t)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, (const char *)packet, MAVLINK_MSG_ID_PARTITION_LEN, MAVLINK_MSG_ID_PARTITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARTITION, (const char *)packet, MAVLINK_MSG_ID_PARTITION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PARTITION UNPACKING


/**
 * @brief Get field ID from partition message
 *
 * @return Partition ID - make this a general purpose message
 */
static inline char mavlink_msg_partition_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  2);
}

/**
 * @brief Get field index from partition message
 *
 * @return First register that was read out.
 */
static inline uint16_t mavlink_msg_partition_get_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field size from partition message
 *
 * @return Holds how many bytes are of importance, begining from index.
 */
static inline uint8_t mavlink_msg_partition_get_size(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field togo from partition message
 *
 * @return Holds how many partitions are still to come. If togo = 0, the last message was received.
 */
static inline uint8_t mavlink_msg_partition_get_togo(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field value from partition message
 *
 * @return Values of the 32 fields, starting from the indicated register
 */
static inline uint16_t mavlink_msg_partition_get_value(const mavlink_message_t* msg, uint8_t *value)
{
	return _MAV_RETURN_uint8_t_array(msg, value, 32,  5);
}

/**
 * @brief Decode a partition message into a struct
 *
 * @param msg The message to decode
 * @param partition C-struct to decode the message contents into
 */
static inline void mavlink_msg_partition_decode(const mavlink_message_t* msg, mavlink_partition_t* partition)
{
#if MAVLINK_NEED_BYTE_SWAP
	partition->index = mavlink_msg_partition_get_index(msg);
	partition->ID = mavlink_msg_partition_get_ID(msg);
	partition->size = mavlink_msg_partition_get_size(msg);
	partition->togo = mavlink_msg_partition_get_togo(msg);
	mavlink_msg_partition_get_value(msg, partition->value);
#else
	memcpy(partition, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PARTITION_LEN);
#endif
}
