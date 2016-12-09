// MESSAGE ATTITUDE_CMD PACKING

#define MAVLINK_MSG_ID_ATTITUDE_CMD 54

typedef struct __mavlink_attitude_cmd_t
{
 int16_t roll; ///< roll command
 int16_t pitch; ///< pitch command
 int16_t yaw; ///< yaw command
 int16_t rollFF; ///< roll feedforward
 int16_t pitchFF; ///< pitch feedforward
 int16_t yawFF; ///< yaw feedforward
} mavlink_attitude_cmd_t;

#define MAVLINK_MSG_ID_ATTITUDE_CMD_LEN 12
#define MAVLINK_MSG_ID_54_LEN 12

#define MAVLINK_MSG_ID_ATTITUDE_CMD_CRC 19
#define MAVLINK_MSG_ID_54_CRC 19



#define MAVLINK_MESSAGE_INFO_ATTITUDE_CMD { \
	"ATTITUDE_CMD", \
	6, \
	{  { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_attitude_cmd_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_attitude_cmd_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_attitude_cmd_t, yaw) }, \
         { "rollFF", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_attitude_cmd_t, rollFF) }, \
         { "pitchFF", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_attitude_cmd_t, pitchFF) }, \
         { "yawFF", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_attitude_cmd_t, yawFF) }, \
         } \
}


/**
 * @brief Pack a attitude_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll roll command
 * @param pitch pitch command
 * @param yaw yaw command
 * @param rollFF roll feedforward
 * @param pitchFF pitch feedforward
 * @param yawFF yaw feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t roll, int16_t pitch, int16_t yaw, int16_t rollFF, int16_t pitchFF, int16_t yawFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_CMD_LEN];
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);
	_mav_put_int16_t(buf, 6, rollFF);
	_mav_put_int16_t(buf, 8, pitchFF);
	_mav_put_int16_t(buf, 10, yawFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#else
	mavlink_attitude_cmd_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollFF = rollFF;
	packet.pitchFF = pitchFF;
	packet.yawFF = yawFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ATTITUDE_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
}

/**
 * @brief Pack a attitude_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll roll command
 * @param pitch pitch command
 * @param yaw yaw command
 * @param rollFF roll feedforward
 * @param pitchFF pitch feedforward
 * @param yawFF yaw feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t roll,int16_t pitch,int16_t yaw,int16_t rollFF,int16_t pitchFF,int16_t yawFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_CMD_LEN];
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);
	_mav_put_int16_t(buf, 6, rollFF);
	_mav_put_int16_t(buf, 8, pitchFF);
	_mav_put_int16_t(buf, 10, yawFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#else
	mavlink_attitude_cmd_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollFF = rollFF;
	packet.pitchFF = pitchFF;
	packet.yawFF = yawFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ATTITUDE_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
}

/**
 * @brief Encode a attitude_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_cmd_t* attitude_cmd)
{
	return mavlink_msg_attitude_cmd_pack(system_id, component_id, msg, attitude_cmd->roll, attitude_cmd->pitch, attitude_cmd->yaw, attitude_cmd->rollFF, attitude_cmd->pitchFF, attitude_cmd->yawFF);
}

/**
 * @brief Encode a attitude_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_cmd_t* attitude_cmd)
{
	return mavlink_msg_attitude_cmd_pack_chan(system_id, component_id, chan, msg, attitude_cmd->roll, attitude_cmd->pitch, attitude_cmd->yaw, attitude_cmd->rollFF, attitude_cmd->pitchFF, attitude_cmd->yawFF);
}

/**
 * @brief Send a attitude_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param roll roll command
 * @param pitch pitch command
 * @param yaw yaw command
 * @param rollFF roll feedforward
 * @param pitchFF pitch feedforward
 * @param yawFF yaw feedforward
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_cmd_send(mavlink_channel_t chan, int16_t roll, int16_t pitch, int16_t yaw, int16_t rollFF, int16_t pitchFF, int16_t yawFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_CMD_LEN];
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);
	_mav_put_int16_t(buf, 6, rollFF);
	_mav_put_int16_t(buf, 8, pitchFF);
	_mav_put_int16_t(buf, 10, yawFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
#else
	mavlink_attitude_cmd_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollFF = rollFF;
	packet.pitchFF = pitchFF;
	packet.yawFF = yawFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_ATTITUDE_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t roll, int16_t pitch, int16_t yaw, int16_t rollFF, int16_t pitchFF, int16_t yawFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);
	_mav_put_int16_t(buf, 6, rollFF);
	_mav_put_int16_t(buf, 8, pitchFF);
	_mav_put_int16_t(buf, 10, yawFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, buf, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
#else
	mavlink_attitude_cmd_t *packet = (mavlink_attitude_cmd_t *)msgbuf;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->rollFF = rollFF;
	packet->pitchFF = pitchFF;
	packet->yawFF = yawFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN, MAVLINK_MSG_ID_ATTITUDE_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_CMD, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE ATTITUDE_CMD UNPACKING


/**
 * @brief Get field roll from attitude_cmd message
 *
 * @return roll command
 */
static inline int16_t mavlink_msg_attitude_cmd_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field pitch from attitude_cmd message
 *
 * @return pitch command
 */
static inline int16_t mavlink_msg_attitude_cmd_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field yaw from attitude_cmd message
 *
 * @return yaw command
 */
static inline int16_t mavlink_msg_attitude_cmd_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field rollFF from attitude_cmd message
 *
 * @return roll feedforward
 */
static inline int16_t mavlink_msg_attitude_cmd_get_rollFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pitchFF from attitude_cmd message
 *
 * @return pitch feedforward
 */
static inline int16_t mavlink_msg_attitude_cmd_get_pitchFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field yawFF from attitude_cmd message
 *
 * @return yaw feedforward
 */
static inline int16_t mavlink_msg_attitude_cmd_get_yawFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Decode a attitude_cmd message into a struct
 *
 * @param msg The message to decode
 * @param attitude_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_cmd_decode(const mavlink_message_t* msg, mavlink_attitude_cmd_t* attitude_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP
	attitude_cmd->roll = mavlink_msg_attitude_cmd_get_roll(msg);
	attitude_cmd->pitch = mavlink_msg_attitude_cmd_get_pitch(msg);
	attitude_cmd->yaw = mavlink_msg_attitude_cmd_get_yaw(msg);
	attitude_cmd->rollFF = mavlink_msg_attitude_cmd_get_rollFF(msg);
	attitude_cmd->pitchFF = mavlink_msg_attitude_cmd_get_pitchFF(msg);
	attitude_cmd->yawFF = mavlink_msg_attitude_cmd_get_yawFF(msg);
#else
	memcpy(attitude_cmd, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ATTITUDE_CMD_LEN);
#endif
}
