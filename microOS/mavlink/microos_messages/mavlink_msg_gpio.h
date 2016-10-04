// MESSAGE GPIO PACKING

#define MAVLINK_MSG_ID_GPIO 3

typedef struct __mavlink_gpio_t
{
 uint32_t time; ///< Time at which the message was sent.
 float gpio_float[8]; ///< 8 gpio floating point values
 int32_t gpio_int[4]; ///< 4 gpio integer values
} mavlink_gpio_t;

#define MAVLINK_MSG_ID_GPIO_LEN 52
#define MAVLINK_MSG_ID_3_LEN 52

#define MAVLINK_MSG_ID_GPIO_CRC 172
#define MAVLINK_MSG_ID_3_CRC 172

#define MAVLINK_MSG_GPIO_FIELD_GPIO_FLOAT_LEN 8
#define MAVLINK_MSG_GPIO_FIELD_GPIO_INT_LEN 4

#define MAVLINK_MESSAGE_INFO_GPIO { \
	"GPIO", \
	3, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gpio_t, time) }, \
         { "gpio_float", NULL, MAVLINK_TYPE_FLOAT, 8, 4, offsetof(mavlink_gpio_t, gpio_float) }, \
         { "gpio_int", NULL, MAVLINK_TYPE_INT32_T, 4, 36, offsetof(mavlink_gpio_t, gpio_int) }, \
         } \
}


/**
 * @brief Pack a gpio message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time Time at which the message was sent.
 * @param gpio_float 8 gpio floating point values
 * @param gpio_int 4 gpio integer values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpio_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, const float *gpio_float, const int32_t *gpio_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPIO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float_array(buf, 4, gpio_float, 8);
	_mav_put_int32_t_array(buf, 36, gpio_int, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIO_LEN);
#else
	mavlink_gpio_t packet;
	packet.time = time;
	mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*8);
	mav_array_memcpy(packet.gpio_int, gpio_int, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPIO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPIO_LEN);
#endif
}

/**
 * @brief Pack a gpio message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Time at which the message was sent.
 * @param gpio_float 8 gpio floating point values
 * @param gpio_int 4 gpio integer values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpio_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,const float *gpio_float,const int32_t *gpio_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPIO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float_array(buf, 4, gpio_float, 8);
	_mav_put_int32_t_array(buf, 36, gpio_int, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIO_LEN);
#else
	mavlink_gpio_t packet;
	packet.time = time;
	mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*8);
	mav_array_memcpy(packet.gpio_int, gpio_int, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPIO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPIO_LEN);
#endif
}

/**
 * @brief Encode a gpio struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpio_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gpio_t* gpio)
{
	return mavlink_msg_gpio_pack(system_id, component_id, msg, gpio->time, gpio->gpio_float, gpio->gpio_int);
}

/**
 * @brief Encode a gpio struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpio_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gpio_t* gpio)
{
	return mavlink_msg_gpio_pack_chan(system_id, component_id, chan, msg, gpio->time, gpio->gpio_float, gpio->gpio_int);
}

/**
 * @brief Send a gpio message
 * @param chan MAVLink channel to send the message
 *
 * @param time Time at which the message was sent.
 * @param gpio_float 8 gpio floating point values
 * @param gpio_int 4 gpio integer values
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gpio_send(mavlink_channel_t chan, uint32_t time, const float *gpio_float, const int32_t *gpio_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPIO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float_array(buf, 4, gpio_float, 8);
	_mav_put_int32_t_array(buf, 36, gpio_int, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_LEN);
#endif
#else
	mavlink_gpio_t packet;
	packet.time = time;
	mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*8);
	mav_array_memcpy(packet.gpio_int, gpio_int, sizeof(int32_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)&packet, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)&packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_GPIO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gpio_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, const float *gpio_float, const int32_t *gpio_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float_array(buf, 4, gpio_float, 8);
	_mav_put_int32_t_array(buf, 36, gpio_int, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_LEN);
#endif
#else
	mavlink_gpio_t *packet = (mavlink_gpio_t *)msgbuf;
	packet->time = time;
	mav_array_memcpy(packet->gpio_float, gpio_float, sizeof(float)*8);
	mav_array_memcpy(packet->gpio_int, gpio_int, sizeof(int32_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)packet, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE GPIO UNPACKING


/**
 * @brief Get field time from gpio message
 *
 * @return Time at which the message was sent.
 */
static inline uint32_t mavlink_msg_gpio_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field gpio_float from gpio message
 *
 * @return 8 gpio floating point values
 */
static inline uint16_t mavlink_msg_gpio_get_gpio_float(const mavlink_message_t* msg, float *gpio_float)
{
	return _MAV_RETURN_float_array(msg, gpio_float, 8,  4);
}

/**
 * @brief Get field gpio_int from gpio message
 *
 * @return 4 gpio integer values
 */
static inline uint16_t mavlink_msg_gpio_get_gpio_int(const mavlink_message_t* msg, int32_t *gpio_int)
{
	return _MAV_RETURN_int32_t_array(msg, gpio_int, 4,  36);
}

/**
 * @brief Decode a gpio message into a struct
 *
 * @param msg The message to decode
 * @param gpio C-struct to decode the message contents into
 */
static inline void mavlink_msg_gpio_decode(const mavlink_message_t* msg, mavlink_gpio_t* gpio)
{
#if MAVLINK_NEED_BYTE_SWAP
	gpio->time = mavlink_msg_gpio_get_time(msg);
	mavlink_msg_gpio_get_gpio_float(msg, gpio->gpio_float);
	mavlink_msg_gpio_get_gpio_int(msg, gpio->gpio_int);
#else
	memcpy(gpio, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GPIO_LEN);
#endif
}
