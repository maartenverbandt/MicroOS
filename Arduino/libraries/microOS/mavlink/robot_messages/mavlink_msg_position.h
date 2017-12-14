// MESSAGE POSITION PACKING

#define MAVLINK_MSG_ID_POSITION 53

typedef struct __mavlink_position_t
{
 uint32_t time; ///< time [us]
 int32_t x; ///< x [mm-sugg.].
 int32_t y; ///< y [mm-sugg.].
 int32_t z; ///< z [mm-sugg.].
 int32_t x_cmd; ///< x command [mm-sugg.].
 int32_t y_cmd; ///< y command [mm-sugg.].
 int32_t z_cmd; ///< z command [mm-sugg.].
 int16_t x_act; ///< x actuator [mrad].
 int16_t y_act; ///< y actuator [mrad]
 int16_t z_act; ///< z actuator [mrad]
 int16_t x_cont; ///< x controller output [mrad].
 int16_t y_cont; ///< y controller output [mrad]
 int16_t z_cont; ///< z controller output [mrad]
} mavlink_position_t;

#define MAVLINK_MSG_ID_POSITION_LEN 40
#define MAVLINK_MSG_ID_53_LEN 40

#define MAVLINK_MSG_ID_POSITION_CRC 27
#define MAVLINK_MSG_ID_53_CRC 27



#define MAVLINK_MESSAGE_INFO_POSITION { \
	"POSITION", \
	13, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_position_t, time) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_position_t, z) }, \
         { "x_cmd", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_position_t, x_cmd) }, \
         { "y_cmd", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_position_t, y_cmd) }, \
         { "z_cmd", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_position_t, z_cmd) }, \
         { "x_act", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_position_t, x_act) }, \
         { "y_act", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_position_t, y_act) }, \
         { "z_act", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_position_t, z_act) }, \
         { "x_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_position_t, x_cont) }, \
         { "y_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_position_t, y_cont) }, \
         { "z_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_position_t, z_cont) }, \
         } \
}


/**
 * @brief Pack a position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_cmd x command [mm-sugg.].
 * @param y_cmd y command [mm-sugg.].
 * @param z_cmd z command [mm-sugg.].
 * @param x_act x actuator [mrad].
 * @param y_act y actuator [mrad]
 * @param z_act z actuator [mrad]
 * @param x_cont x controller output [mrad].
 * @param y_cont y controller output [mrad]
 * @param z_cont z controller output [mrad]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int32_t x, int32_t y, int32_t z, int32_t x_cmd, int32_t y_cmd, int32_t z_cmd, int16_t x_act, int16_t y_act, int16_t z_act, int16_t x_cont, int16_t y_cont, int16_t z_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, x);
	_mav_put_int32_t(buf, 8, y);
	_mav_put_int32_t(buf, 12, z);
	_mav_put_int32_t(buf, 16, x_cmd);
	_mav_put_int32_t(buf, 20, y_cmd);
	_mav_put_int32_t(buf, 24, z_cmd);
	_mav_put_int16_t(buf, 28, x_act);
	_mav_put_int16_t(buf, 30, y_act);
	_mav_put_int16_t(buf, 32, z_act);
	_mav_put_int16_t(buf, 34, x_cont);
	_mav_put_int16_t(buf, 36, y_cont);
	_mav_put_int16_t(buf, 38, z_cont);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_cmd = x_cmd;
	packet.y_cmd = y_cmd;
	packet.z_cmd = z_cmd;
	packet.x_act = x_act;
	packet.y_act = y_act;
	packet.z_act = z_act;
	packet.x_cont = x_cont;
	packet.y_cont = y_cont;
	packet.z_cont = z_cont;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_LEN);
#endif
}

/**
 * @brief Pack a position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_cmd x command [mm-sugg.].
 * @param y_cmd y command [mm-sugg.].
 * @param z_cmd z command [mm-sugg.].
 * @param x_act x actuator [mrad].
 * @param y_act y actuator [mrad]
 * @param z_act z actuator [mrad]
 * @param x_cont x controller output [mrad].
 * @param y_cont y controller output [mrad]
 * @param z_cont z controller output [mrad]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int32_t x,int32_t y,int32_t z,int32_t x_cmd,int32_t y_cmd,int32_t z_cmd,int16_t x_act,int16_t y_act,int16_t z_act,int16_t x_cont,int16_t y_cont,int16_t z_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, x);
	_mav_put_int32_t(buf, 8, y);
	_mav_put_int32_t(buf, 12, z);
	_mav_put_int32_t(buf, 16, x_cmd);
	_mav_put_int32_t(buf, 20, y_cmd);
	_mav_put_int32_t(buf, 24, z_cmd);
	_mav_put_int16_t(buf, 28, x_act);
	_mav_put_int16_t(buf, 30, y_act);
	_mav_put_int16_t(buf, 32, z_act);
	_mav_put_int16_t(buf, 34, x_cont);
	_mav_put_int16_t(buf, 36, y_cont);
	_mav_put_int16_t(buf, 38, z_cont);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_cmd = x_cmd;
	packet.y_cmd = y_cmd;
	packet.z_cmd = z_cmd;
	packet.x_act = x_act;
	packet.y_act = y_act;
	packet.z_act = z_act;
	packet.x_cont = x_cont;
	packet.y_cont = y_cont;
	packet.z_cont = z_cont;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_LEN);
#endif
}

/**
 * @brief Encode a position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_t* position)
{
	return mavlink_msg_position_pack(system_id, component_id, msg, position->time, position->x, position->y, position->z, position->x_cmd, position->y_cmd, position->z_cmd, position->x_act, position->y_act, position->z_act, position->x_cont, position->y_cont, position->z_cont);
}

/**
 * @brief Encode a position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_t* position)
{
	return mavlink_msg_position_pack_chan(system_id, component_id, chan, msg, position->time, position->x, position->y, position->z, position->x_cmd, position->y_cmd, position->z_cmd, position->x_act, position->y_act, position->z_act, position->x_cont, position->y_cont, position->z_cont);
}

/**
 * @brief Send a position message
 * @param chan MAVLink channel to send the message
 *
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_cmd x command [mm-sugg.].
 * @param y_cmd y command [mm-sugg.].
 * @param z_cmd z command [mm-sugg.].
 * @param x_act x actuator [mrad].
 * @param y_act y actuator [mrad]
 * @param z_act z actuator [mrad]
 * @param x_cont x controller output [mrad].
 * @param y_cont y controller output [mrad]
 * @param z_cont z controller output [mrad]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_send(mavlink_channel_t chan, uint32_t time, int32_t x, int32_t y, int32_t z, int32_t x_cmd, int32_t y_cmd, int32_t z_cmd, int16_t x_act, int16_t y_act, int16_t z_act, int16_t x_cont, int16_t y_cont, int16_t z_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, x);
	_mav_put_int32_t(buf, 8, y);
	_mav_put_int32_t(buf, 12, z);
	_mav_put_int32_t(buf, 16, x_cmd);
	_mav_put_int32_t(buf, 20, y_cmd);
	_mav_put_int32_t(buf, 24, z_cmd);
	_mav_put_int16_t(buf, 28, x_act);
	_mav_put_int16_t(buf, 30, y_act);
	_mav_put_int16_t(buf, 32, z_act);
	_mav_put_int16_t(buf, 34, x_cont);
	_mav_put_int16_t(buf, 36, y_cont);
	_mav_put_int16_t(buf, 38, z_cont);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_cmd = x_cmd;
	packet.y_cmd = y_cmd;
	packet.z_cmd = z_cmd;
	packet.x_act = x_act;
	packet.y_act = y_act;
	packet.z_act = z_act;
	packet.x_cont = x_cont;
	packet.y_cont = y_cont;
	packet.z_cont = z_cont;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)&packet, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)&packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int32_t x, int32_t y, int32_t z, int32_t x_cmd, int32_t y_cmd, int32_t z_cmd, int16_t x_act, int16_t y_act, int16_t z_act, int16_t x_cont, int16_t y_cont, int16_t z_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, x);
	_mav_put_int32_t(buf, 8, y);
	_mav_put_int32_t(buf, 12, z);
	_mav_put_int32_t(buf, 16, x_cmd);
	_mav_put_int32_t(buf, 20, y_cmd);
	_mav_put_int32_t(buf, 24, z_cmd);
	_mav_put_int16_t(buf, 28, x_act);
	_mav_put_int16_t(buf, 30, y_act);
	_mav_put_int16_t(buf, 32, z_act);
	_mav_put_int16_t(buf, 34, x_cont);
	_mav_put_int16_t(buf, 36, y_cont);
	_mav_put_int16_t(buf, 38, z_cont);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#else
	mavlink_position_t *packet = (mavlink_position_t *)msgbuf;
	packet->time = time;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->x_cmd = x_cmd;
	packet->y_cmd = y_cmd;
	packet->z_cmd = z_cmd;
	packet->x_act = x_act;
	packet->y_act = y_act;
	packet->z_act = z_act;
	packet->x_cont = x_cont;
	packet->y_cont = y_cont;
	packet->z_cont = z_cont;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)packet, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE POSITION UNPACKING


/**
 * @brief Get field time from position message
 *
 * @return time [us]
 */
static inline uint32_t mavlink_msg_position_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field x from position message
 *
 * @return x [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field y from position message
 *
 * @return y [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field z from position message
 *
 * @return z [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field x_cmd from position message
 *
 * @return x command [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_x_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field y_cmd from position message
 *
 * @return y command [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_y_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field z_cmd from position message
 *
 * @return z command [mm-sugg.].
 */
static inline int32_t mavlink_msg_position_get_z_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field x_act from position message
 *
 * @return x actuator [mrad].
 */
static inline int16_t mavlink_msg_position_get_x_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field y_act from position message
 *
 * @return y actuator [mrad]
 */
static inline int16_t mavlink_msg_position_get_y_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field z_act from position message
 *
 * @return z actuator [mrad]
 */
static inline int16_t mavlink_msg_position_get_z_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field x_cont from position message
 *
 * @return x controller output [mrad].
 */
static inline int16_t mavlink_msg_position_get_x_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field y_cont from position message
 *
 * @return y controller output [mrad]
 */
static inline int16_t mavlink_msg_position_get_y_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field z_cont from position message
 *
 * @return z controller output [mrad]
 */
static inline int16_t mavlink_msg_position_get_z_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Decode a position message into a struct
 *
 * @param msg The message to decode
 * @param position C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_decode(const mavlink_message_t* msg, mavlink_position_t* position)
{
#if MAVLINK_NEED_BYTE_SWAP
	position->time = mavlink_msg_position_get_time(msg);
	position->x = mavlink_msg_position_get_x(msg);
	position->y = mavlink_msg_position_get_y(msg);
	position->z = mavlink_msg_position_get_z(msg);
	position->x_cmd = mavlink_msg_position_get_x_cmd(msg);
	position->y_cmd = mavlink_msg_position_get_y_cmd(msg);
	position->z_cmd = mavlink_msg_position_get_z_cmd(msg);
	position->x_act = mavlink_msg_position_get_x_act(msg);
	position->y_act = mavlink_msg_position_get_y_act(msg);
	position->z_act = mavlink_msg_position_get_z_act(msg);
	position->x_cont = mavlink_msg_position_get_x_cont(msg);
	position->y_cont = mavlink_msg_position_get_y_cont(msg);
	position->z_cont = mavlink_msg_position_get_z_cont(msg);
#else
	memcpy(position, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_POSITION_LEN);
#endif
}
