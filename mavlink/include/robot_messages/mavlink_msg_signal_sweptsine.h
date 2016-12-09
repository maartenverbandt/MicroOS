// MESSAGE SIGNAL_SWEPTSINE PACKING

#define MAVLINK_MSG_ID_SIGNAL_SWEPTSINE 80

typedef struct __mavlink_signal_sweptsine_t
{
 float fmin; ///< Minimum excitation frequency.
 float fmax; ///< Maximum excitation frequency.
 float period; ///< period of the excitation
 float amplitude; ///< amplitude of the excitation
 uint16_t channels; ///< Contains the channels which will be excited.
} mavlink_signal_sweptsine_t;

#define MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN 18
#define MAVLINK_MSG_ID_80_LEN 18

#define MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC 41
#define MAVLINK_MSG_ID_80_CRC 41



#define MAVLINK_MESSAGE_INFO_SIGNAL_SWEPTSINE { \
	"SIGNAL_SWEPTSINE", \
	5, \
	{  { "fmin", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_signal_sweptsine_t, fmin) }, \
         { "fmax", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_signal_sweptsine_t, fmax) }, \
         { "period", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_signal_sweptsine_t, period) }, \
         { "amplitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_signal_sweptsine_t, amplitude) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_signal_sweptsine_t, channels) }, \
         } \
}


/**
 * @brief Pack a signal_sweptsine message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period period of the excitation
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_sweptsine_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t channels, float fmin, float fmax, float period, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, period);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#else
	mavlink_signal_sweptsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.period = period;
	packet.amplitude = amplitude;
	packet.channels = channels;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_SWEPTSINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
}

/**
 * @brief Pack a signal_sweptsine message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period period of the excitation
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_sweptsine_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t channels,float fmin,float fmax,float period,float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, period);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#else
	mavlink_signal_sweptsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.period = period;
	packet.amplitude = amplitude;
	packet.channels = channels;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_SWEPTSINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
}

/**
 * @brief Encode a signal_sweptsine struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param signal_sweptsine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_sweptsine_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_signal_sweptsine_t* signal_sweptsine)
{
	return mavlink_msg_signal_sweptsine_pack(system_id, component_id, msg, signal_sweptsine->channels, signal_sweptsine->fmin, signal_sweptsine->fmax, signal_sweptsine->period, signal_sweptsine->amplitude);
}

/**
 * @brief Encode a signal_sweptsine struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal_sweptsine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_sweptsine_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_signal_sweptsine_t* signal_sweptsine)
{
	return mavlink_msg_signal_sweptsine_pack_chan(system_id, component_id, chan, msg, signal_sweptsine->channels, signal_sweptsine->fmin, signal_sweptsine->fmax, signal_sweptsine->period, signal_sweptsine->amplitude);
}

/**
 * @brief Send a signal_sweptsine message
 * @param chan MAVLink channel to send the message
 *
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period period of the excitation
 * @param amplitude amplitude of the excitation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_signal_sweptsine_send(mavlink_channel_t chan, uint16_t channels, float fmin, float fmax, float period, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, period);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
#else
	mavlink_signal_sweptsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.period = period;
	packet.amplitude = amplitude;
	packet.channels = channels;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_signal_sweptsine_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t channels, float fmin, float fmax, float period, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, period);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, buf, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
#else
	mavlink_signal_sweptsine_t *packet = (mavlink_signal_sweptsine_t *)msgbuf;
	packet->fmin = fmin;
	packet->fmax = fmax;
	packet->period = period;
	packet->amplitude = amplitude;
	packet->channels = channels;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SIGNAL_SWEPTSINE UNPACKING


/**
 * @brief Get field channels from signal_sweptsine message
 *
 * @return Contains the channels which will be excited.
 */
static inline uint16_t mavlink_msg_signal_sweptsine_get_channels(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field fmin from signal_sweptsine message
 *
 * @return Minimum excitation frequency.
 */
static inline float mavlink_msg_signal_sweptsine_get_fmin(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field fmax from signal_sweptsine message
 *
 * @return Maximum excitation frequency.
 */
static inline float mavlink_msg_signal_sweptsine_get_fmax(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field period from signal_sweptsine message
 *
 * @return period of the excitation
 */
static inline float mavlink_msg_signal_sweptsine_get_period(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field amplitude from signal_sweptsine message
 *
 * @return amplitude of the excitation
 */
static inline float mavlink_msg_signal_sweptsine_get_amplitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a signal_sweptsine message into a struct
 *
 * @param msg The message to decode
 * @param signal_sweptsine C-struct to decode the message contents into
 */
static inline void mavlink_msg_signal_sweptsine_decode(const mavlink_message_t* msg, mavlink_signal_sweptsine_t* signal_sweptsine)
{
#if MAVLINK_NEED_BYTE_SWAP
	signal_sweptsine->fmin = mavlink_msg_signal_sweptsine_get_fmin(msg);
	signal_sweptsine->fmax = mavlink_msg_signal_sweptsine_get_fmax(msg);
	signal_sweptsine->period = mavlink_msg_signal_sweptsine_get_period(msg);
	signal_sweptsine->amplitude = mavlink_msg_signal_sweptsine_get_amplitude(msg);
	signal_sweptsine->channels = mavlink_msg_signal_sweptsine_get_channels(msg);
#else
	memcpy(signal_sweptsine, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SIGNAL_SWEPTSINE_LEN);
#endif
}
