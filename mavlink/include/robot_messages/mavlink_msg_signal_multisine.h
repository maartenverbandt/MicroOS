// MESSAGE SIGNAL_MULTISINE PACKING

#define MAVLINK_MSG_ID_SIGNAL_MULTISINE 81

typedef struct __mavlink_signal_multisine_t
{
 float amplitude; ///< amplitude of the excitation
 uint16_t channels; ///< Contains the channels which will be excited.
 uint8_t id; ///< Choose a predefined multisine
} mavlink_signal_multisine_t;

#define MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN 7
#define MAVLINK_MSG_ID_81_LEN 7

#define MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC 237
#define MAVLINK_MSG_ID_81_CRC 237



#define MAVLINK_MESSAGE_INFO_SIGNAL_MULTISINE { \
	"SIGNAL_MULTISINE", \
	3, \
	{  { "amplitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_signal_multisine_t, amplitude) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_signal_multisine_t, channels) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_signal_multisine_t, id) }, \
         } \
}


/**
 * @brief Pack a signal_multisine message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param channels Contains the channels which will be excited.
 * @param id Choose a predefined multisine
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_multisine_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t channels, uint8_t id, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN];
	_mav_put_float(buf, 0, amplitude);
	_mav_put_uint16_t(buf, 4, channels);
	_mav_put_uint8_t(buf, 6, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#else
	mavlink_signal_multisine_t packet;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_MULTISINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
}

/**
 * @brief Pack a signal_multisine message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param channels Contains the channels which will be excited.
 * @param id Choose a predefined multisine
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_multisine_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t channels,uint8_t id,float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN];
	_mav_put_float(buf, 0, amplitude);
	_mav_put_uint16_t(buf, 4, channels);
	_mav_put_uint8_t(buf, 6, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#else
	mavlink_signal_multisine_t packet;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_MULTISINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
}

/**
 * @brief Encode a signal_multisine struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param signal_multisine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_multisine_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_signal_multisine_t* signal_multisine)
{
	return mavlink_msg_signal_multisine_pack(system_id, component_id, msg, signal_multisine->channels, signal_multisine->id, signal_multisine->amplitude);
}

/**
 * @brief Encode a signal_multisine struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal_multisine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_multisine_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_signal_multisine_t* signal_multisine)
{
	return mavlink_msg_signal_multisine_pack_chan(system_id, component_id, chan, msg, signal_multisine->channels, signal_multisine->id, signal_multisine->amplitude);
}

/**
 * @brief Send a signal_multisine message
 * @param chan MAVLink channel to send the message
 *
 * @param channels Contains the channels which will be excited.
 * @param id Choose a predefined multisine
 * @param amplitude amplitude of the excitation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_signal_multisine_send(mavlink_channel_t chan, uint16_t channels, uint8_t id, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN];
	_mav_put_float(buf, 0, amplitude);
	_mav_put_uint16_t(buf, 4, channels);
	_mav_put_uint8_t(buf, 6, id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
#else
	mavlink_signal_multisine_t packet;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.id = id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_signal_multisine_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t channels, uint8_t id, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, amplitude);
	_mav_put_uint16_t(buf, 4, channels);
	_mav_put_uint8_t(buf, 6, id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, buf, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
#else
	mavlink_signal_multisine_t *packet = (mavlink_signal_multisine_t *)msgbuf;
	packet->amplitude = amplitude;
	packet->channels = channels;
	packet->id = id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN, MAVLINK_MSG_ID_SIGNAL_MULTISINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_MULTISINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SIGNAL_MULTISINE UNPACKING


/**
 * @brief Get field channels from signal_multisine message
 *
 * @return Contains the channels which will be excited.
 */
static inline uint16_t mavlink_msg_signal_multisine_get_channels(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field id from signal_multisine message
 *
 * @return Choose a predefined multisine
 */
static inline uint8_t mavlink_msg_signal_multisine_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field amplitude from signal_multisine message
 *
 * @return amplitude of the excitation
 */
static inline float mavlink_msg_signal_multisine_get_amplitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a signal_multisine message into a struct
 *
 * @param msg The message to decode
 * @param signal_multisine C-struct to decode the message contents into
 */
static inline void mavlink_msg_signal_multisine_decode(const mavlink_message_t* msg, mavlink_signal_multisine_t* signal_multisine)
{
#if MAVLINK_NEED_BYTE_SWAP
	signal_multisine->amplitude = mavlink_msg_signal_multisine_get_amplitude(msg);
	signal_multisine->channels = mavlink_msg_signal_multisine_get_channels(msg);
	signal_multisine->id = mavlink_msg_signal_multisine_get_id(msg);
#else
	memcpy(signal_multisine, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SIGNAL_MULTISINE_LEN);
#endif
}
