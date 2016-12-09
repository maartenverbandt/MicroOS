// MESSAGE CHANNEL_IO PACKING

#define MAVLINK_MSG_ID_CHANNEL_IO 102

typedef struct __mavlink_channel_io_t
{
 uint32_t time; ///< TimeStamp
 float input[6]; ///< Input to the channel
 float output[6]; ///< Output of the channel
 uint8_t sync; ///< Synchronization value
} mavlink_channel_io_t;

#define MAVLINK_MSG_ID_CHANNEL_IO_LEN 53
#define MAVLINK_MSG_ID_102_LEN 53

#define MAVLINK_MSG_ID_CHANNEL_IO_CRC 156
#define MAVLINK_MSG_ID_102_CRC 156

#define MAVLINK_MSG_CHANNEL_IO_FIELD_INPUT_LEN 6
#define MAVLINK_MSG_CHANNEL_IO_FIELD_OUTPUT_LEN 6

#define MAVLINK_MESSAGE_INFO_CHANNEL_IO { \
	"CHANNEL_IO", \
	4, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_channel_io_t, time) }, \
         { "input", NULL, MAVLINK_TYPE_FLOAT, 6, 4, offsetof(mavlink_channel_io_t, input) }, \
         { "output", NULL, MAVLINK_TYPE_FLOAT, 6, 28, offsetof(mavlink_channel_io_t, output) }, \
         { "sync", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_channel_io_t, sync) }, \
         } \
}


/**
 * @brief Pack a channel_io message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time TimeStamp
 * @param sync Synchronization value
 * @param input Input to the channel
 * @param output Output of the channel
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_channel_io_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, uint8_t sync, const float *input, const float *output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint8_t(buf, 52, sync);
	_mav_put_float_array(buf, 4, input, 6);
	_mav_put_float_array(buf, 28, output, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#else
	mavlink_channel_io_t packet;
	packet.time = time;
	packet.sync = sync;
	mav_array_memcpy(packet.input, input, sizeof(float)*6);
	mav_array_memcpy(packet.output, output, sizeof(float)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CHANNEL_IO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
}

/**
 * @brief Pack a channel_io message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time TimeStamp
 * @param sync Synchronization value
 * @param input Input to the channel
 * @param output Output of the channel
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_channel_io_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,uint8_t sync,const float *input,const float *output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint8_t(buf, 52, sync);
	_mav_put_float_array(buf, 4, input, 6);
	_mav_put_float_array(buf, 28, output, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#else
	mavlink_channel_io_t packet;
	packet.time = time;
	packet.sync = sync;
	mav_array_memcpy(packet.input, input, sizeof(float)*6);
	mav_array_memcpy(packet.output, output, sizeof(float)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CHANNEL_IO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
}

/**
 * @brief Encode a channel_io struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param channel_io C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_channel_io_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_channel_io_t* channel_io)
{
	return mavlink_msg_channel_io_pack(system_id, component_id, msg, channel_io->time, channel_io->sync, channel_io->input, channel_io->output);
}

/**
 * @brief Encode a channel_io struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param channel_io C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_channel_io_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_channel_io_t* channel_io)
{
	return mavlink_msg_channel_io_pack_chan(system_id, component_id, chan, msg, channel_io->time, channel_io->sync, channel_io->input, channel_io->output);
}

/**
 * @brief Send a channel_io message
 * @param chan MAVLink channel to send the message
 *
 * @param time TimeStamp
 * @param sync Synchronization value
 * @param input Input to the channel
 * @param output Output of the channel
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_channel_io_send(mavlink_channel_t chan, uint32_t time, uint8_t sync, const float *input, const float *output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint8_t(buf, 52, sync);
	_mav_put_float_array(buf, 4, input, 6);
	_mav_put_float_array(buf, 28, output, 6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
#else
	mavlink_channel_io_t packet;
	packet.time = time;
	packet.sync = sync;
	mav_array_memcpy(packet.input, input, sizeof(float)*6);
	mav_array_memcpy(packet.output, output, sizeof(float)*6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, (const char *)&packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, (const char *)&packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_CHANNEL_IO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_channel_io_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, uint8_t sync, const float *input, const float *output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint8_t(buf, 52, sync);
	_mav_put_float_array(buf, 4, input, 6);
	_mav_put_float_array(buf, 28, output, 6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, buf, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
#else
	mavlink_channel_io_t *packet = (mavlink_channel_io_t *)msgbuf;
	packet->time = time;
	packet->sync = sync;
	mav_array_memcpy(packet->input, input, sizeof(float)*6);
	mav_array_memcpy(packet->output, output, sizeof(float)*6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, (const char *)packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO, (const char *)packet, MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE CHANNEL_IO UNPACKING


/**
 * @brief Get field time from channel_io message
 *
 * @return TimeStamp
 */
static inline uint32_t mavlink_msg_channel_io_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sync from channel_io message
 *
 * @return Synchronization value
 */
static inline uint8_t mavlink_msg_channel_io_get_sync(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field input from channel_io message
 *
 * @return Input to the channel
 */
static inline uint16_t mavlink_msg_channel_io_get_input(const mavlink_message_t* msg, float *input)
{
	return _MAV_RETURN_float_array(msg, input, 6,  4);
}

/**
 * @brief Get field output from channel_io message
 *
 * @return Output of the channel
 */
static inline uint16_t mavlink_msg_channel_io_get_output(const mavlink_message_t* msg, float *output)
{
	return _MAV_RETURN_float_array(msg, output, 6,  28);
}

/**
 * @brief Decode a channel_io message into a struct
 *
 * @param msg The message to decode
 * @param channel_io C-struct to decode the message contents into
 */
static inline void mavlink_msg_channel_io_decode(const mavlink_message_t* msg, mavlink_channel_io_t* channel_io)
{
#if MAVLINK_NEED_BYTE_SWAP
	channel_io->time = mavlink_msg_channel_io_get_time(msg);
	mavlink_msg_channel_io_get_input(msg, channel_io->input);
	mavlink_msg_channel_io_get_output(msg, channel_io->output);
	channel_io->sync = mavlink_msg_channel_io_get_sync(msg);
#else
	memcpy(channel_io, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_CHANNEL_IO_LEN);
#endif
}
