// MESSAGE SIGNAL_STEPPEDSINE PACKING

#define MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE 82

typedef struct __mavlink_signal_steppedsine_t
{
 float fmin; ///< Minimum excitation frequency.
 float fmax; ///< Maximum excitation frequency.
 float stepsize; ///< frequency step size
 float amplitude; ///< amplitude of the excitation
 uint16_t channels; ///< Contains the channels which will be excited.
 uint8_t period; ///< for how many periods the sine should run
} mavlink_signal_steppedsine_t;

#define MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN 19
#define MAVLINK_MSG_ID_82_LEN 19

#define MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC 15
#define MAVLINK_MSG_ID_82_CRC 15



#define MAVLINK_MESSAGE_INFO_SIGNAL_STEPPEDSINE { \
	"SIGNAL_STEPPEDSINE", \
	6, \
	{  { "fmin", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_signal_steppedsine_t, fmin) }, \
         { "fmax", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_signal_steppedsine_t, fmax) }, \
         { "stepsize", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_signal_steppedsine_t, stepsize) }, \
         { "amplitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_signal_steppedsine_t, amplitude) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_signal_steppedsine_t, channels) }, \
         { "period", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_signal_steppedsine_t, period) }, \
         } \
}


/**
 * @brief Pack a signal_steppedsine message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period for how many periods the sine should run
 * @param stepsize frequency step size
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_steppedsine_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t channels, float fmin, float fmax, uint8_t period, float stepsize, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, stepsize);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, period);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#else
	mavlink_signal_steppedsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.stepsize = stepsize;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.period = period;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
}

/**
 * @brief Pack a signal_steppedsine message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period for how many periods the sine should run
 * @param stepsize frequency step size
 * @param amplitude amplitude of the excitation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_steppedsine_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t channels,float fmin,float fmax,uint8_t period,float stepsize,float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, stepsize);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, period);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#else
	mavlink_signal_steppedsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.stepsize = stepsize;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.period = period;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
}

/**
 * @brief Encode a signal_steppedsine struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param signal_steppedsine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_steppedsine_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_signal_steppedsine_t* signal_steppedsine)
{
	return mavlink_msg_signal_steppedsine_pack(system_id, component_id, msg, signal_steppedsine->channels, signal_steppedsine->fmin, signal_steppedsine->fmax, signal_steppedsine->period, signal_steppedsine->stepsize, signal_steppedsine->amplitude);
}

/**
 * @brief Encode a signal_steppedsine struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal_steppedsine C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_steppedsine_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_signal_steppedsine_t* signal_steppedsine)
{
	return mavlink_msg_signal_steppedsine_pack_chan(system_id, component_id, chan, msg, signal_steppedsine->channels, signal_steppedsine->fmin, signal_steppedsine->fmax, signal_steppedsine->period, signal_steppedsine->stepsize, signal_steppedsine->amplitude);
}

/**
 * @brief Send a signal_steppedsine message
 * @param chan MAVLink channel to send the message
 *
 * @param channels Contains the channels which will be excited.
 * @param fmin Minimum excitation frequency.
 * @param fmax Maximum excitation frequency.
 * @param period for how many periods the sine should run
 * @param stepsize frequency step size
 * @param amplitude amplitude of the excitation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_signal_steppedsine_send(mavlink_channel_t chan, uint16_t channels, float fmin, float fmax, uint8_t period, float stepsize, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN];
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, stepsize);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, period);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
#else
	mavlink_signal_steppedsine_t packet;
	packet.fmin = fmin;
	packet.fmax = fmax;
	packet.stepsize = stepsize;
	packet.amplitude = amplitude;
	packet.channels = channels;
	packet.period = period;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_signal_steppedsine_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t channels, float fmin, float fmax, uint8_t period, float stepsize, float amplitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, fmin);
	_mav_put_float(buf, 4, fmax);
	_mav_put_float(buf, 8, stepsize);
	_mav_put_float(buf, 12, amplitude);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, period);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, buf, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
#else
	mavlink_signal_steppedsine_t *packet = (mavlink_signal_steppedsine_t *)msgbuf;
	packet->fmin = fmin;
	packet->fmax = fmax;
	packet->stepsize = stepsize;
	packet->amplitude = amplitude;
	packet->channels = channels;
	packet->period = period;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SIGNAL_STEPPEDSINE UNPACKING


/**
 * @brief Get field channels from signal_steppedsine message
 *
 * @return Contains the channels which will be excited.
 */
static inline uint16_t mavlink_msg_signal_steppedsine_get_channels(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field fmin from signal_steppedsine message
 *
 * @return Minimum excitation frequency.
 */
static inline float mavlink_msg_signal_steppedsine_get_fmin(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field fmax from signal_steppedsine message
 *
 * @return Maximum excitation frequency.
 */
static inline float mavlink_msg_signal_steppedsine_get_fmax(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field period from signal_steppedsine message
 *
 * @return for how many periods the sine should run
 */
static inline uint8_t mavlink_msg_signal_steppedsine_get_period(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field stepsize from signal_steppedsine message
 *
 * @return frequency step size
 */
static inline float mavlink_msg_signal_steppedsine_get_stepsize(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field amplitude from signal_steppedsine message
 *
 * @return amplitude of the excitation
 */
static inline float mavlink_msg_signal_steppedsine_get_amplitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a signal_steppedsine message into a struct
 *
 * @param msg The message to decode
 * @param signal_steppedsine C-struct to decode the message contents into
 */
static inline void mavlink_msg_signal_steppedsine_decode(const mavlink_message_t* msg, mavlink_signal_steppedsine_t* signal_steppedsine)
{
#if MAVLINK_NEED_BYTE_SWAP
	signal_steppedsine->fmin = mavlink_msg_signal_steppedsine_get_fmin(msg);
	signal_steppedsine->fmax = mavlink_msg_signal_steppedsine_get_fmax(msg);
	signal_steppedsine->stepsize = mavlink_msg_signal_steppedsine_get_stepsize(msg);
	signal_steppedsine->amplitude = mavlink_msg_signal_steppedsine_get_amplitude(msg);
	signal_steppedsine->channels = mavlink_msg_signal_steppedsine_get_channels(msg);
	signal_steppedsine->period = mavlink_msg_signal_steppedsine_get_period(msg);
#else
	memcpy(signal_steppedsine, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE_LEN);
#endif
}
