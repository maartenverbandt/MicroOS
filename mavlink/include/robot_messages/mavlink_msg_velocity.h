// MESSAGE VELOCITY PACKING

#define MAVLINK_MSG_ID_VELOCITY 52

typedef struct __mavlink_velocity_t
{
 uint32_t time; ///< time [us]
 int16_t vx; ///< x velocity [mm/s].
 int16_t vy; ///< y velocity [mm/s]
 int16_t vz; ///< z velocity [mm/s]
 int16_t vx_cmd; ///< x velocity command [mm/s].
 int16_t vy_cmd; ///< y velocity command [mm/s]
 int16_t vz_cmd; ///< z velocity command [mm/s]
 int16_t vx_act; ///< x velocity actuator [mrad-sugg.].
 int16_t vy_act; ///< y velocity actuator [mrad-sugg.].
 int16_t vz_act; ///< z velocity actuator [mrad-sugg.].
 int16_t vx_cont; ///< x velocity controller output [mrad-sugg.].
 int16_t vy_cont; ///< y velocity controller output [mrad-sugg.].
 int16_t vz_cont; ///< z velocity controller output [mrad-sugg.].
} mavlink_velocity_t;

#define MAVLINK_MSG_ID_VELOCITY_LEN 28
#define MAVLINK_MSG_ID_52_LEN 28

#define MAVLINK_MSG_ID_VELOCITY_CRC 97
#define MAVLINK_MSG_ID_52_CRC 97



#define MAVLINK_MESSAGE_INFO_VELOCITY { \
	"VELOCITY", \
	13, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_velocity_t, time) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_velocity_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_velocity_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_velocity_t, vz) }, \
         { "vx_cmd", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_velocity_t, vx_cmd) }, \
         { "vy_cmd", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_velocity_t, vy_cmd) }, \
         { "vz_cmd", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_velocity_t, vz_cmd) }, \
         { "vx_act", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_velocity_t, vx_act) }, \
         { "vy_act", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_velocity_t, vy_act) }, \
         { "vz_act", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_velocity_t, vz_act) }, \
         { "vx_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_velocity_t, vx_cont) }, \
         { "vy_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_velocity_t, vy_cont) }, \
         { "vz_cont", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_velocity_t, vz_cont) }, \
         } \
}


/**
 * @brief Pack a velocity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time time [us]
 * @param vx x velocity [mm/s].
 * @param vy y velocity [mm/s]
 * @param vz z velocity [mm/s]
 * @param vx_cmd x velocity command [mm/s].
 * @param vy_cmd y velocity command [mm/s]
 * @param vz_cmd z velocity command [mm/s]
 * @param vx_act x velocity actuator [mrad-sugg.].
 * @param vy_act y velocity actuator [mrad-sugg.].
 * @param vz_act z velocity actuator [mrad-sugg.].
 * @param vx_cont x velocity controller output [mrad-sugg.].
 * @param vy_cont y velocity controller output [mrad-sugg.].
 * @param vz_cont z velocity controller output [mrad-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_cmd, int16_t vy_cmd, int16_t vz_cmd, int16_t vx_act, int16_t vy_act, int16_t vz_act, int16_t vx_cont, int16_t vy_cont, int16_t vz_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_cmd);
	_mav_put_int16_t(buf, 12, vy_cmd);
	_mav_put_int16_t(buf, 14, vz_cmd);
	_mav_put_int16_t(buf, 16, vx_act);
	_mav_put_int16_t(buf, 18, vy_act);
	_mav_put_int16_t(buf, 20, vz_act);
	_mav_put_int16_t(buf, 22, vx_cont);
	_mav_put_int16_t(buf, 24, vy_cont);
	_mav_put_int16_t(buf, 26, vz_cont);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_cmd = vx_cmd;
	packet.vy_cmd = vy_cmd;
	packet.vz_cmd = vz_cmd;
	packet.vx_act = vx_act;
	packet.vy_act = vy_act;
	packet.vz_act = vz_act;
	packet.vx_cont = vx_cont;
	packet.vy_cont = vy_cont;
	packet.vz_cont = vz_cont;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}

/**
 * @brief Pack a velocity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time time [us]
 * @param vx x velocity [mm/s].
 * @param vy y velocity [mm/s]
 * @param vz z velocity [mm/s]
 * @param vx_cmd x velocity command [mm/s].
 * @param vy_cmd y velocity command [mm/s]
 * @param vz_cmd z velocity command [mm/s]
 * @param vx_act x velocity actuator [mrad-sugg.].
 * @param vy_act y velocity actuator [mrad-sugg.].
 * @param vz_act z velocity actuator [mrad-sugg.].
 * @param vx_cont x velocity controller output [mrad-sugg.].
 * @param vy_cont y velocity controller output [mrad-sugg.].
 * @param vz_cont z velocity controller output [mrad-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t vx,int16_t vy,int16_t vz,int16_t vx_cmd,int16_t vy_cmd,int16_t vz_cmd,int16_t vx_act,int16_t vy_act,int16_t vz_act,int16_t vx_cont,int16_t vy_cont,int16_t vz_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_cmd);
	_mav_put_int16_t(buf, 12, vy_cmd);
	_mav_put_int16_t(buf, 14, vz_cmd);
	_mav_put_int16_t(buf, 16, vx_act);
	_mav_put_int16_t(buf, 18, vy_act);
	_mav_put_int16_t(buf, 20, vz_act);
	_mav_put_int16_t(buf, 22, vx_cont);
	_mav_put_int16_t(buf, 24, vy_cont);
	_mav_put_int16_t(buf, 26, vz_cont);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_cmd = vx_cmd;
	packet.vy_cmd = vy_cmd;
	packet.vz_cmd = vz_cmd;
	packet.vx_act = vx_act;
	packet.vy_act = vy_act;
	packet.vz_act = vz_act;
	packet.vx_cont = vx_cont;
	packet.vy_cont = vy_cont;
	packet.vz_cont = vz_cont;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}

/**
 * @brief Encode a velocity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_velocity_t* velocity)
{
	return mavlink_msg_velocity_pack(system_id, component_id, msg, velocity->time, velocity->vx, velocity->vy, velocity->vz, velocity->vx_cmd, velocity->vy_cmd, velocity->vz_cmd, velocity->vx_act, velocity->vy_act, velocity->vz_act, velocity->vx_cont, velocity->vy_cont, velocity->vz_cont);
}

/**
 * @brief Encode a velocity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_velocity_t* velocity)
{
	return mavlink_msg_velocity_pack_chan(system_id, component_id, chan, msg, velocity->time, velocity->vx, velocity->vy, velocity->vz, velocity->vx_cmd, velocity->vy_cmd, velocity->vz_cmd, velocity->vx_act, velocity->vy_act, velocity->vz_act, velocity->vx_cont, velocity->vy_cont, velocity->vz_cont);
}

/**
 * @brief Send a velocity message
 * @param chan MAVLink channel to send the message
 *
 * @param time time [us]
 * @param vx x velocity [mm/s].
 * @param vy y velocity [mm/s]
 * @param vz z velocity [mm/s]
 * @param vx_cmd x velocity command [mm/s].
 * @param vy_cmd y velocity command [mm/s]
 * @param vz_cmd z velocity command [mm/s]
 * @param vx_act x velocity actuator [mrad-sugg.].
 * @param vy_act y velocity actuator [mrad-sugg.].
 * @param vz_act z velocity actuator [mrad-sugg.].
 * @param vx_cont x velocity controller output [mrad-sugg.].
 * @param vy_cont y velocity controller output [mrad-sugg.].
 * @param vz_cont z velocity controller output [mrad-sugg.].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_velocity_send(mavlink_channel_t chan, uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_cmd, int16_t vy_cmd, int16_t vz_cmd, int16_t vx_act, int16_t vy_act, int16_t vz_act, int16_t vx_cont, int16_t vy_cont, int16_t vz_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_cmd);
	_mav_put_int16_t(buf, 12, vy_cmd);
	_mav_put_int16_t(buf, 14, vz_cmd);
	_mav_put_int16_t(buf, 16, vx_act);
	_mav_put_int16_t(buf, 18, vy_act);
	_mav_put_int16_t(buf, 20, vz_act);
	_mav_put_int16_t(buf, 22, vx_cont);
	_mav_put_int16_t(buf, 24, vy_cont);
	_mav_put_int16_t(buf, 26, vz_cont);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_cmd = vx_cmd;
	packet.vy_cmd = vy_cmd;
	packet.vz_cmd = vz_cmd;
	packet.vx_act = vx_act;
	packet.vy_act = vy_act;
	packet.vz_act = vz_act;
	packet.vx_cont = vx_cont;
	packet.vy_cont = vy_cont;
	packet.vz_cont = vz_cont;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VELOCITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_velocity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_cmd, int16_t vy_cmd, int16_t vz_cmd, int16_t vx_act, int16_t vy_act, int16_t vz_act, int16_t vx_cont, int16_t vy_cont, int16_t vz_cont)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_cmd);
	_mav_put_int16_t(buf, 12, vy_cmd);
	_mav_put_int16_t(buf, 14, vz_cmd);
	_mav_put_int16_t(buf, 16, vx_act);
	_mav_put_int16_t(buf, 18, vy_act);
	_mav_put_int16_t(buf, 20, vz_act);
	_mav_put_int16_t(buf, 22, vx_cont);
	_mav_put_int16_t(buf, 24, vy_cont);
	_mav_put_int16_t(buf, 26, vz_cont);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#else
	mavlink_velocity_t *packet = (mavlink_velocity_t *)msgbuf;
	packet->time = time;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;
	packet->vx_cmd = vx_cmd;
	packet->vy_cmd = vy_cmd;
	packet->vz_cmd = vz_cmd;
	packet->vx_act = vx_act;
	packet->vy_act = vy_act;
	packet->vz_act = vz_act;
	packet->vx_cont = vx_cont;
	packet->vy_cont = vy_cont;
	packet->vz_cont = vz_cont;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VELOCITY UNPACKING


/**
 * @brief Get field time from velocity message
 *
 * @return time [us]
 */
static inline uint32_t mavlink_msg_velocity_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vx from velocity message
 *
 * @return x velocity [mm/s].
 */
static inline int16_t mavlink_msg_velocity_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field vy from velocity message
 *
 * @return y velocity [mm/s]
 */
static inline int16_t mavlink_msg_velocity_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field vz from velocity message
 *
 * @return z velocity [mm/s]
 */
static inline int16_t mavlink_msg_velocity_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field vx_cmd from velocity message
 *
 * @return x velocity command [mm/s].
 */
static inline int16_t mavlink_msg_velocity_get_vx_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field vy_cmd from velocity message
 *
 * @return y velocity command [mm/s]
 */
static inline int16_t mavlink_msg_velocity_get_vy_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field vz_cmd from velocity message
 *
 * @return z velocity command [mm/s]
 */
static inline int16_t mavlink_msg_velocity_get_vz_cmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field vx_act from velocity message
 *
 * @return x velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vx_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field vy_act from velocity message
 *
 * @return y velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vy_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field vz_act from velocity message
 *
 * @return z velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vz_act(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field vx_cont from velocity message
 *
 * @return x velocity controller output [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vx_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field vy_cont from velocity message
 *
 * @return y velocity controller output [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vy_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field vz_cont from velocity message
 *
 * @return z velocity controller output [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vz_cont(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Decode a velocity message into a struct
 *
 * @param msg The message to decode
 * @param velocity C-struct to decode the message contents into
 */
static inline void mavlink_msg_velocity_decode(const mavlink_message_t* msg, mavlink_velocity_t* velocity)
{
#if MAVLINK_NEED_BYTE_SWAP
	velocity->time = mavlink_msg_velocity_get_time(msg);
	velocity->vx = mavlink_msg_velocity_get_vx(msg);
	velocity->vy = mavlink_msg_velocity_get_vy(msg);
	velocity->vz = mavlink_msg_velocity_get_vz(msg);
	velocity->vx_cmd = mavlink_msg_velocity_get_vx_cmd(msg);
	velocity->vy_cmd = mavlink_msg_velocity_get_vy_cmd(msg);
	velocity->vz_cmd = mavlink_msg_velocity_get_vz_cmd(msg);
	velocity->vx_act = mavlink_msg_velocity_get_vx_act(msg);
	velocity->vy_act = mavlink_msg_velocity_get_vy_act(msg);
	velocity->vz_act = mavlink_msg_velocity_get_vz_act(msg);
	velocity->vx_cont = mavlink_msg_velocity_get_vx_cont(msg);
	velocity->vy_cont = mavlink_msg_velocity_get_vy_cont(msg);
	velocity->vz_cont = mavlink_msg_velocity_get_vz_cont(msg);
#else
	memcpy(velocity, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}
