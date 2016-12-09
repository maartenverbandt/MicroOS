// MESSAGE VELOCITY_CMD PACKING

#define MAVLINK_MSG_ID_VELOCITY_CMD 55

typedef struct __mavlink_velocity_cmd_t
{
 int16_t vx; ///< x velocity command
 int16_t vy; ///< y velocity command
 int16_t vz; ///< z velocity command
 int16_t vxFF; ///< x velocity feedforward
 int16_t vyFF; ///< y velocity feedforward
 int16_t vzFF; ///< z velocity feedforward
} mavlink_velocity_cmd_t;

#define MAVLINK_MSG_ID_VELOCITY_CMD_LEN 12
#define MAVLINK_MSG_ID_55_LEN 12

#define MAVLINK_MSG_ID_VELOCITY_CMD_CRC 172
#define MAVLINK_MSG_ID_55_CRC 172



#define MAVLINK_MESSAGE_INFO_VELOCITY_CMD { \
	"VELOCITY_CMD", \
	6, \
	{  { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_velocity_cmd_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_velocity_cmd_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_velocity_cmd_t, vz) }, \
         { "vxFF", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_velocity_cmd_t, vxFF) }, \
         { "vyFF", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_velocity_cmd_t, vyFF) }, \
         { "vzFF", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_velocity_cmd_t, vzFF) }, \
         } \
}


/**
 * @brief Pack a velocity_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vx x velocity command
 * @param vy y velocity command
 * @param vz z velocity command
 * @param vxFF x velocity feedforward
 * @param vyFF y velocity feedforward
 * @param vzFF z velocity feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t vx, int16_t vy, int16_t vz, int16_t vxFF, int16_t vyFF, int16_t vzFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_CMD_LEN];
	_mav_put_int16_t(buf, 0, vx);
	_mav_put_int16_t(buf, 2, vy);
	_mav_put_int16_t(buf, 4, vz);
	_mav_put_int16_t(buf, 6, vxFF);
	_mav_put_int16_t(buf, 8, vyFF);
	_mav_put_int16_t(buf, 10, vzFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#else
	mavlink_velocity_cmd_t packet;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vxFF = vxFF;
	packet.vyFF = vyFF;
	packet.vzFF = vzFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
}

/**
 * @brief Pack a velocity_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vx x velocity command
 * @param vy y velocity command
 * @param vz z velocity command
 * @param vxFF x velocity feedforward
 * @param vyFF y velocity feedforward
 * @param vzFF z velocity feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t vx,int16_t vy,int16_t vz,int16_t vxFF,int16_t vyFF,int16_t vzFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_CMD_LEN];
	_mav_put_int16_t(buf, 0, vx);
	_mav_put_int16_t(buf, 2, vy);
	_mav_put_int16_t(buf, 4, vz);
	_mav_put_int16_t(buf, 6, vxFF);
	_mav_put_int16_t(buf, 8, vyFF);
	_mav_put_int16_t(buf, 10, vzFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#else
	mavlink_velocity_cmd_t packet;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vxFF = vxFF;
	packet.vyFF = vyFF;
	packet.vzFF = vzFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
}

/**
 * @brief Encode a velocity_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param velocity_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_velocity_cmd_t* velocity_cmd)
{
	return mavlink_msg_velocity_cmd_pack(system_id, component_id, msg, velocity_cmd->vx, velocity_cmd->vy, velocity_cmd->vz, velocity_cmd->vxFF, velocity_cmd->vyFF, velocity_cmd->vzFF);
}

/**
 * @brief Encode a velocity_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param velocity_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_velocity_cmd_t* velocity_cmd)
{
	return mavlink_msg_velocity_cmd_pack_chan(system_id, component_id, chan, msg, velocity_cmd->vx, velocity_cmd->vy, velocity_cmd->vz, velocity_cmd->vxFF, velocity_cmd->vyFF, velocity_cmd->vzFF);
}

/**
 * @brief Send a velocity_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param vx x velocity command
 * @param vy y velocity command
 * @param vz z velocity command
 * @param vxFF x velocity feedforward
 * @param vyFF y velocity feedforward
 * @param vzFF z velocity feedforward
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_velocity_cmd_send(mavlink_channel_t chan, int16_t vx, int16_t vy, int16_t vz, int16_t vxFF, int16_t vyFF, int16_t vzFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_CMD_LEN];
	_mav_put_int16_t(buf, 0, vx);
	_mav_put_int16_t(buf, 2, vy);
	_mav_put_int16_t(buf, 4, vz);
	_mav_put_int16_t(buf, 6, vxFF);
	_mav_put_int16_t(buf, 8, vyFF);
	_mav_put_int16_t(buf, 10, vzFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
#else
	mavlink_velocity_cmd_t packet;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vxFF = vxFF;
	packet.vyFF = vyFF;
	packet.vzFF = vzFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VELOCITY_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_velocity_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t vx, int16_t vy, int16_t vz, int16_t vxFF, int16_t vyFF, int16_t vzFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, vx);
	_mav_put_int16_t(buf, 2, vy);
	_mav_put_int16_t(buf, 4, vz);
	_mav_put_int16_t(buf, 6, vxFF);
	_mav_put_int16_t(buf, 8, vyFF);
	_mav_put_int16_t(buf, 10, vzFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, buf, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
#else
	mavlink_velocity_cmd_t *packet = (mavlink_velocity_cmd_t *)msgbuf;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;
	packet->vxFF = vxFF;
	packet->vyFF = vyFF;
	packet->vzFF = vzFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN, MAVLINK_MSG_ID_VELOCITY_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_CMD, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VELOCITY_CMD UNPACKING


/**
 * @brief Get field vx from velocity_cmd message
 *
 * @return x velocity command
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field vy from velocity_cmd message
 *
 * @return y velocity command
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field vz from velocity_cmd message
 *
 * @return z velocity command
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field vxFF from velocity_cmd message
 *
 * @return x velocity feedforward
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vxFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field vyFF from velocity_cmd message
 *
 * @return y velocity feedforward
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vyFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field vzFF from velocity_cmd message
 *
 * @return z velocity feedforward
 */
static inline int16_t mavlink_msg_velocity_cmd_get_vzFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Decode a velocity_cmd message into a struct
 *
 * @param msg The message to decode
 * @param velocity_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_velocity_cmd_decode(const mavlink_message_t* msg, mavlink_velocity_cmd_t* velocity_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP
	velocity_cmd->vx = mavlink_msg_velocity_cmd_get_vx(msg);
	velocity_cmd->vy = mavlink_msg_velocity_cmd_get_vy(msg);
	velocity_cmd->vz = mavlink_msg_velocity_cmd_get_vz(msg);
	velocity_cmd->vxFF = mavlink_msg_velocity_cmd_get_vxFF(msg);
	velocity_cmd->vyFF = mavlink_msg_velocity_cmd_get_vyFF(msg);
	velocity_cmd->vzFF = mavlink_msg_velocity_cmd_get_vzFF(msg);
#else
	memcpy(velocity_cmd, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VELOCITY_CMD_LEN);
#endif
}
