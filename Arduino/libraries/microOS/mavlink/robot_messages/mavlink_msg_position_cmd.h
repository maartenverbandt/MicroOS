// MESSAGE POSITION_CMD PACKING

#define MAVLINK_MSG_ID_POSITION_CMD 56

typedef struct __mavlink_position_cmd_t
{
 int32_t x; ///< x command
 int32_t y; ///< y command
 int32_t z; ///< z command
 int16_t xFF; ///< x feedforward
 int16_t yFF; ///< y feedforward
 int16_t zFF; ///< z feedforward
} mavlink_position_cmd_t;

#define MAVLINK_MSG_ID_POSITION_CMD_LEN 18
#define MAVLINK_MSG_ID_56_LEN 18

#define MAVLINK_MSG_ID_POSITION_CMD_CRC 122
#define MAVLINK_MSG_ID_56_CRC 122



#define MAVLINK_MESSAGE_INFO_POSITION_CMD { \
	"POSITION_CMD", \
	6, \
	{  { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_position_cmd_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_position_cmd_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_position_cmd_t, z) }, \
         { "xFF", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_position_cmd_t, xFF) }, \
         { "yFF", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_position_cmd_t, yFF) }, \
         { "zFF", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_position_cmd_t, zFF) }, \
         } \
}


/**
 * @brief Pack a position_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x x command
 * @param y y command
 * @param z z command
 * @param xFF x feedforward
 * @param yFF y feedforward
 * @param zFF z feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t x, int32_t y, int32_t z, int16_t xFF, int16_t yFF, int16_t zFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CMD_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, xFF);
	_mav_put_int16_t(buf, 14, yFF);
	_mav_put_int16_t(buf, 16, zFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#else
	mavlink_position_cmd_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.xFF = xFF;
	packet.yFF = yFF;
	packet.zFF = zFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
}

/**
 * @brief Pack a position_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x command
 * @param y y command
 * @param z z command
 * @param xFF x feedforward
 * @param yFF y feedforward
 * @param zFF z feedforward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t x,int32_t y,int32_t z,int16_t xFF,int16_t yFF,int16_t zFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CMD_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, xFF);
	_mav_put_int16_t(buf, 14, yFF);
	_mav_put_int16_t(buf, 16, zFF);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#else
	mavlink_position_cmd_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.xFF = xFF;
	packet.yFF = yFF;
	packet.zFF = zFF;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
}

/**
 * @brief Encode a position_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_cmd_t* position_cmd)
{
	return mavlink_msg_position_cmd_pack(system_id, component_id, msg, position_cmd->x, position_cmd->y, position_cmd->z, position_cmd->xFF, position_cmd->yFF, position_cmd->zFF);
}

/**
 * @brief Encode a position_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_cmd_t* position_cmd)
{
	return mavlink_msg_position_cmd_pack_chan(system_id, component_id, chan, msg, position_cmd->x, position_cmd->y, position_cmd->z, position_cmd->xFF, position_cmd->yFF, position_cmd->zFF);
}

/**
 * @brief Send a position_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param x x command
 * @param y y command
 * @param z z command
 * @param xFF x feedforward
 * @param yFF y feedforward
 * @param zFF z feedforward
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_cmd_send(mavlink_channel_t chan, int32_t x, int32_t y, int32_t z, int16_t xFF, int16_t yFF, int16_t zFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CMD_LEN];
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, xFF);
	_mav_put_int16_t(buf, 14, yFF);
	_mav_put_int16_t(buf, 16, zFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, buf, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, buf, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
#else
	mavlink_position_cmd_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.xFF = xFF;
	packet.yFF = yFF;
	packet.zFF = zFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, (const char *)&packet, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, (const char *)&packet, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_POSITION_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t x, int32_t y, int32_t z, int16_t xFF, int16_t yFF, int16_t zFF)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, x);
	_mav_put_int32_t(buf, 4, y);
	_mav_put_int32_t(buf, 8, z);
	_mav_put_int16_t(buf, 12, xFF);
	_mav_put_int16_t(buf, 14, yFF);
	_mav_put_int16_t(buf, 16, zFF);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, buf, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, buf, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
#else
	mavlink_position_cmd_t *packet = (mavlink_position_cmd_t *)msgbuf;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->xFF = xFF;
	packet->yFF = yFF;
	packet->zFF = zFF;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, (const char *)packet, MAVLINK_MSG_ID_POSITION_CMD_LEN, MAVLINK_MSG_ID_POSITION_CMD_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CMD, (const char *)packet, MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE POSITION_CMD UNPACKING


/**
 * @brief Get field x from position_cmd message
 *
 * @return x command
 */
static inline int32_t mavlink_msg_position_cmd_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field y from position_cmd message
 *
 * @return y command
 */
static inline int32_t mavlink_msg_position_cmd_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field z from position_cmd message
 *
 * @return z command
 */
static inline int32_t mavlink_msg_position_cmd_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field xFF from position_cmd message
 *
 * @return x feedforward
 */
static inline int16_t mavlink_msg_position_cmd_get_xFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field yFF from position_cmd message
 *
 * @return y feedforward
 */
static inline int16_t mavlink_msg_position_cmd_get_yFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field zFF from position_cmd message
 *
 * @return z feedforward
 */
static inline int16_t mavlink_msg_position_cmd_get_zFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a position_cmd message into a struct
 *
 * @param msg The message to decode
 * @param position_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_cmd_decode(const mavlink_message_t* msg, mavlink_position_cmd_t* position_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP
	position_cmd->x = mavlink_msg_position_cmd_get_x(msg);
	position_cmd->y = mavlink_msg_position_cmd_get_y(msg);
	position_cmd->z = mavlink_msg_position_cmd_get_z(msg);
	position_cmd->xFF = mavlink_msg_position_cmd_get_xFF(msg);
	position_cmd->yFF = mavlink_msg_position_cmd_get_yFF(msg);
	position_cmd->zFF = mavlink_msg_position_cmd_get_zFF(msg);
#else
	memcpy(position_cmd, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_POSITION_CMD_LEN);
#endif
}
