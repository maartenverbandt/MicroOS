// MESSAGE RADAR_CLOUD PACKING

#define MAVLINK_MSG_ID_RADAR_CLOUD 70

typedef struct __mavlink_radar_cloud_t
{
 int32_t x[6]; ///< x [mm-sugg.].
 int32_t y[6]; ///< y [mm-sugg.].
} mavlink_radar_cloud_t;

#define MAVLINK_MSG_ID_RADAR_CLOUD_LEN 48
#define MAVLINK_MSG_ID_70_LEN 48

#define MAVLINK_MSG_ID_RADAR_CLOUD_CRC 158
#define MAVLINK_MSG_ID_70_CRC 158

#define MAVLINK_MSG_RADAR_CLOUD_FIELD_X_LEN 6
#define MAVLINK_MSG_RADAR_CLOUD_FIELD_Y_LEN 6

#define MAVLINK_MESSAGE_INFO_RADAR_CLOUD { \
	"RADAR_CLOUD", \
	2, \
	{  { "x", NULL, MAVLINK_TYPE_INT32_T, 6, 0, offsetof(mavlink_radar_cloud_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 6, 24, offsetof(mavlink_radar_cloud_t, y) }, \
         } \
}


/**
 * @brief Pack a radar_cloud message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_cloud_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_CLOUD_LEN];

	_mav_put_int32_t_array(buf, 0, x, 6);
	_mav_put_int32_t_array(buf, 24, y, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#else
	mavlink_radar_cloud_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*6);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RADAR_CLOUD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
}

/**
 * @brief Pack a radar_cloud message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_cloud_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const int32_t *x,const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_CLOUD_LEN];

	_mav_put_int32_t_array(buf, 0, x, 6);
	_mav_put_int32_t_array(buf, 24, y, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#else
	mavlink_radar_cloud_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*6);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RADAR_CLOUD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
}

/**
 * @brief Encode a radar_cloud struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radar_cloud C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_cloud_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radar_cloud_t* radar_cloud)
{
	return mavlink_msg_radar_cloud_pack(system_id, component_id, msg, radar_cloud->x, radar_cloud->y);
}

/**
 * @brief Encode a radar_cloud struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radar_cloud C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_cloud_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radar_cloud_t* radar_cloud)
{
	return mavlink_msg_radar_cloud_pack_chan(system_id, component_id, chan, msg, radar_cloud->x, radar_cloud->y);
}

/**
 * @brief Send a radar_cloud message
 * @param chan MAVLink channel to send the message
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radar_cloud_send(mavlink_channel_t chan, const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_CLOUD_LEN];

	_mav_put_int32_t_array(buf, 0, x, 6);
	_mav_put_int32_t_array(buf, 24, y, 6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
#else
	mavlink_radar_cloud_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*6);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, (const char *)&packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, (const char *)&packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RADAR_CLOUD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radar_cloud_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_int32_t_array(buf, 0, x, 6);
	_mav_put_int32_t_array(buf, 24, y, 6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, buf, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
#else
	mavlink_radar_cloud_t *packet = (mavlink_radar_cloud_t *)msgbuf;

	mav_array_memcpy(packet->x, x, sizeof(int32_t)*6);
	mav_array_memcpy(packet->y, y, sizeof(int32_t)*6);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, (const char *)packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN, MAVLINK_MSG_ID_RADAR_CLOUD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_CLOUD, (const char *)packet, MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RADAR_CLOUD UNPACKING


/**
 * @brief Get field x from radar_cloud message
 *
 * @return x [mm-sugg.].
 */
static inline uint16_t mavlink_msg_radar_cloud_get_x(const mavlink_message_t* msg, int32_t *x)
{
	return _MAV_RETURN_int32_t_array(msg, x, 6,  0);
}

/**
 * @brief Get field y from radar_cloud message
 *
 * @return y [mm-sugg.].
 */
static inline uint16_t mavlink_msg_radar_cloud_get_y(const mavlink_message_t* msg, int32_t *y)
{
	return _MAV_RETURN_int32_t_array(msg, y, 6,  24);
}

/**
 * @brief Decode a radar_cloud message into a struct
 *
 * @param msg The message to decode
 * @param radar_cloud C-struct to decode the message contents into
 */
static inline void mavlink_msg_radar_cloud_decode(const mavlink_message_t* msg, mavlink_radar_cloud_t* radar_cloud)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_radar_cloud_get_x(msg, radar_cloud->x);
	mavlink_msg_radar_cloud_get_y(msg, radar_cloud->y);
#else
	memcpy(radar_cloud, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RADAR_CLOUD_LEN);
#endif
}
