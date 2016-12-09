// MESSAGE POSE PACKING

#define MAVLINK_MSG_ID_POSE 50

typedef struct __mavlink_pose_t
{
 int32_t x; ///< x [mm-sugg.].
 int32_t y; ///< y [mm-sugg.].
 int32_t z; ///< z [mm-sugg.].
 int16_t roll; ///< roll [mrad-sugg.].
 int16_t pitch; ///< pitch [mrad-sugg.]
 int16_t yaw; ///< yaw [mrad-sugg.]
} mavlink_pose_t;

#define MAVLINK_MSG_ID_POSE_LEN 18
#define MAVLINK_MSG_ID_50_LEN 18

#define MAVLINK_MSG_ID_POSE_CRC 97
#define MAVLINK_MSG_ID_50_CRC 97



#define MAVLINK_MESSAGE_INFO_POSE { \
	"POSE", \
	6, \
	{  { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_pose_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_pose_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_pose_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_pose_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_pose_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_pose_t, yaw) }, \
         } \
}


/**
 * @brief Pack a pose message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pose_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t x, int32_t y, int32_t z, int16_t roll, int16_t pitch, int16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSE_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, roll);
	_mav_put_int16_t(buf, 14, pitch);
	_mav_put_int16_t(buf, 16, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSE_LEN);
#else
	mavlink_pose_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSE_LEN);
#endif
}

/**
 * @brief Pack a pose message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pose_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t x,int32_t y,int32_t z,int16_t roll,int16_t pitch,int16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSE_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, roll);
	_mav_put_int16_t(buf, 14, pitch);
	_mav_put_int16_t(buf, 16, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSE_LEN);
#else
	mavlink_pose_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSE_LEN);
#endif
}

/**
 * @brief Encode a pose struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pose_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pose_t* pose)
{
	return mavlink_msg_pose_pack(system_id, component_id, msg, pose->x, pose->y, pose->z, pose->roll, pose->pitch, pose->yaw);
}

/**
 * @brief Encode a pose struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pose_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pose_t* pose)
{
	return mavlink_msg_pose_pack_chan(system_id, component_id, chan, msg, pose->x, pose->y, pose->z, pose->roll, pose->pitch, pose->yaw);
}

/**
 * @brief Send a pose message
 * @param chan MAVLink channel to send the message
 *
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pose_send(mavlink_channel_t chan, int32_t x, int32_t y, int32_t z, int16_t roll, int16_t pitch, int16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSE_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, roll);
	_mav_put_int16_t(buf, 14, pitch);
	_mav_put_int16_t(buf, 16, yaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_LEN);
#endif
#else
	mavlink_pose_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)&packet, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)&packet, MAVLINK_MSG_ID_POSE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_POSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pose_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t x, int32_t y, int32_t z, int16_t roll, int16_t pitch, int16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, roll);
	_mav_put_int16_t(buf, 14, pitch);
	_mav_put_int16_t(buf, 16, yaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_LEN);
#endif
#else
	mavlink_pose_t *packet = (mavlink_pose_t *)msgbuf;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)packet, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)packet, MAVLINK_MSG_ID_POSE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE POSE UNPACKING


/**
 * @brief Get field x from pose message
 *
 * @return x [mm-sugg.].
 */
static inline int32_t mavlink_msg_pose_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field y from pose message
 *
 * @return y [mm-sugg.].
 */
static inline int32_t mavlink_msg_pose_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field z from pose message
 *
 * @return z [mm-sugg.].
 */
static inline int32_t mavlink_msg_pose_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field roll from pose message
 *
 * @return roll [mrad-sugg.].
 */
static inline int16_t mavlink_msg_pose_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field pitch from pose message
 *
 * @return pitch [mrad-sugg.]
 */
static inline int16_t mavlink_msg_pose_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field yaw from pose message
 *
 * @return yaw [mrad-sugg.]
 */
static inline int16_t mavlink_msg_pose_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a pose message into a struct
 *
 * @param msg The message to decode
 * @param pose C-struct to decode the message contents into
 */
static inline void mavlink_msg_pose_decode(const mavlink_message_t* msg, mavlink_pose_t* pose)
{
#if MAVLINK_NEED_BYTE_SWAP
	pose->x = mavlink_msg_pose_get_x(msg);
	pose->y = mavlink_msg_pose_get_y(msg);
	pose->z = mavlink_msg_pose_get_z(msg);
	pose->roll = mavlink_msg_pose_get_roll(msg);
	pose->pitch = mavlink_msg_pose_get_pitch(msg);
	pose->yaw = mavlink_msg_pose_get_yaw(msg);
#else
	memcpy(pose, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_POSE_LEN);
#endif
}
