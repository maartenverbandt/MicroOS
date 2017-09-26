// MESSAGE RADAR_LINE PACKING

#define MAVLINK_MSG_ID_RADAR_LINE 71

typedef struct __mavlink_radar_line_t
{
 int32_t x[2]; ///< x [mm-sugg.].
 int32_t y[2]; ///< y [mm-sugg.].
} mavlink_radar_line_t;

#define MAVLINK_MSG_ID_RADAR_LINE_LEN 16
#define MAVLINK_MSG_ID_71_LEN 16

#define MAVLINK_MSG_ID_RADAR_LINE_CRC 230
#define MAVLINK_MSG_ID_71_CRC 230

#define MAVLINK_MSG_RADAR_LINE_FIELD_X_LEN 2
#define MAVLINK_MSG_RADAR_LINE_FIELD_Y_LEN 2

#define MAVLINK_MESSAGE_INFO_RADAR_LINE { \
	"RADAR_LINE", \
	2, \
	{  { "x", NULL, MAVLINK_TYPE_INT32_T, 2, 0, offsetof(mavlink_radar_line_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 2, 8, offsetof(mavlink_radar_line_t, y) }, \
         } \
}


/**
 * @brief Pack a radar_line message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_line_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_LINE_LEN];

	_mav_put_int32_t_array(buf, 0, x, 2);
	_mav_put_int32_t_array(buf, 8, y, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#else
	mavlink_radar_line_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*2);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RADAR_LINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
}

/**
 * @brief Pack a radar_line message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_line_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const int32_t *x,const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_LINE_LEN];

	_mav_put_int32_t_array(buf, 0, x, 2);
	_mav_put_int32_t_array(buf, 8, y, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#else
	mavlink_radar_line_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*2);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RADAR_LINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
}

/**
 * @brief Encode a radar_line struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radar_line C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_line_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radar_line_t* radar_line)
{
	return mavlink_msg_radar_line_pack(system_id, component_id, msg, radar_line->x, radar_line->y);
}

/**
 * @brief Encode a radar_line struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radar_line C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_line_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radar_line_t* radar_line)
{
	return mavlink_msg_radar_line_pack_chan(system_id, component_id, chan, msg, radar_line->x, radar_line->y);
}

/**
 * @brief Send a radar_line message
 * @param chan MAVLink channel to send the message
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radar_line_send(mavlink_channel_t chan, const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RADAR_LINE_LEN];

	_mav_put_int32_t_array(buf, 0, x, 2);
	_mav_put_int32_t_array(buf, 8, y, 2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, buf, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, buf, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
#else
	mavlink_radar_line_t packet;

	mav_array_memcpy(packet.x, x, sizeof(int32_t)*2);
	mav_array_memcpy(packet.y, y, sizeof(int32_t)*2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, (const char *)&packet, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, (const char *)&packet, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RADAR_LINE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radar_line_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int32_t *x, const int32_t *y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_int32_t_array(buf, 0, x, 2);
	_mav_put_int32_t_array(buf, 8, y, 2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, buf, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, buf, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
#else
	mavlink_radar_line_t *packet = (mavlink_radar_line_t *)msgbuf;

	mav_array_memcpy(packet->x, x, sizeof(int32_t)*2);
	mav_array_memcpy(packet->y, y, sizeof(int32_t)*2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, (const char *)packet, MAVLINK_MSG_ID_RADAR_LINE_LEN, MAVLINK_MSG_ID_RADAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_LINE, (const char *)packet, MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RADAR_LINE UNPACKING


/**
 * @brief Get field x from radar_line message
 *
 * @return x [mm-sugg.].
 */
static inline uint16_t mavlink_msg_radar_line_get_x(const mavlink_message_t* msg, int32_t *x)
{
	return _MAV_RETURN_int32_t_array(msg, x, 2,  0);
}

/**
 * @brief Get field y from radar_line message
 *
 * @return y [mm-sugg.].
 */
static inline uint16_t mavlink_msg_radar_line_get_y(const mavlink_message_t* msg, int32_t *y)
{
	return _MAV_RETURN_int32_t_array(msg, y, 2,  8);
}

/**
 * @brief Decode a radar_line message into a struct
 *
 * @param msg The message to decode
 * @param radar_line C-struct to decode the message contents into
 */
static inline void mavlink_msg_radar_line_decode(const mavlink_message_t* msg, mavlink_radar_line_t* radar_line)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_radar_line_get_x(msg, radar_line->x);
	mavlink_msg_radar_line_get_y(msg, radar_line->y);
#else
	memcpy(radar_line, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RADAR_LINE_LEN);
#endif
}
