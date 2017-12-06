// MESSAGE CHANNEL_IO_INFO PACKING

#define MAVLINK_MSG_ID_CHANNEL_IO_INFO 103

typedef struct __mavlink_channel_io_info_t
{
 uint8_t type; ///< Type of excitation: stepped sine, sweptsine, multisine,...
 uint8_t configuration; ///< Which inputs and outputs are selected. Choose one out of many default configurations
 uint8_t excitation; ///< Which channels where excited
 uint8_t version; ///< log file version
 uint8_t subversion; ///< log file version
} mavlink_channel_io_info_t;

#define MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN 5
#define MAVLINK_MSG_ID_103_LEN 5

#define MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC 102
#define MAVLINK_MSG_ID_103_CRC 102



#define MAVLINK_MESSAGE_INFO_CHANNEL_IO_INFO { \
	"CHANNEL_IO_INFO", \
	5, \
	{  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_channel_io_info_t, type) }, \
         { "configuration", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_channel_io_info_t, configuration) }, \
         { "excitation", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_channel_io_info_t, excitation) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_channel_io_info_t, version) }, \
         { "subversion", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_channel_io_info_t, subversion) }, \
         } \
}


/**
 * @brief Pack a channel_io_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type Type of excitation: stepped sine, sweptsine, multisine,...
 * @param configuration Which inputs and outputs are selected. Choose one out of many default configurations
 * @param excitation Which channels where excited
 * @param version log file version
 * @param subversion log file version
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_channel_io_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t type, uint8_t configuration, uint8_t excitation, uint8_t version, uint8_t subversion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, configuration);
	_mav_put_uint8_t(buf, 2, excitation);
	_mav_put_uint8_t(buf, 3, version);
	_mav_put_uint8_t(buf, 4, subversion);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#else
	mavlink_channel_io_info_t packet;
	packet.type = type;
	packet.configuration = configuration;
	packet.excitation = excitation;
	packet.version = version;
	packet.subversion = subversion;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CHANNEL_IO_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
}

/**
 * @brief Pack a channel_io_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type Type of excitation: stepped sine, sweptsine, multisine,...
 * @param configuration Which inputs and outputs are selected. Choose one out of many default configurations
 * @param excitation Which channels where excited
 * @param version log file version
 * @param subversion log file version
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_channel_io_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t type,uint8_t configuration,uint8_t excitation,uint8_t version,uint8_t subversion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, configuration);
	_mav_put_uint8_t(buf, 2, excitation);
	_mav_put_uint8_t(buf, 3, version);
	_mav_put_uint8_t(buf, 4, subversion);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#else
	mavlink_channel_io_info_t packet;
	packet.type = type;
	packet.configuration = configuration;
	packet.excitation = excitation;
	packet.version = version;
	packet.subversion = subversion;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CHANNEL_IO_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
}

/**
 * @brief Encode a channel_io_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param channel_io_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_channel_io_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_channel_io_info_t* channel_io_info)
{
	return mavlink_msg_channel_io_info_pack(system_id, component_id, msg, channel_io_info->type, channel_io_info->configuration, channel_io_info->excitation, channel_io_info->version, channel_io_info->subversion);
}

/**
 * @brief Encode a channel_io_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param channel_io_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_channel_io_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_channel_io_info_t* channel_io_info)
{
	return mavlink_msg_channel_io_info_pack_chan(system_id, component_id, chan, msg, channel_io_info->type, channel_io_info->configuration, channel_io_info->excitation, channel_io_info->version, channel_io_info->subversion);
}

/**
 * @brief Send a channel_io_info message
 * @param chan MAVLink channel to send the message
 *
 * @param type Type of excitation: stepped sine, sweptsine, multisine,...
 * @param configuration Which inputs and outputs are selected. Choose one out of many default configurations
 * @param excitation Which channels where excited
 * @param version log file version
 * @param subversion log file version
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_channel_io_info_send(mavlink_channel_t chan, uint8_t type, uint8_t configuration, uint8_t excitation, uint8_t version, uint8_t subversion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, configuration);
	_mav_put_uint8_t(buf, 2, excitation);
	_mav_put_uint8_t(buf, 3, version);
	_mav_put_uint8_t(buf, 4, subversion);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
#else
	mavlink_channel_io_info_t packet;
	packet.type = type;
	packet.configuration = configuration;
	packet.excitation = excitation;
	packet.version = version;
	packet.subversion = subversion;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, (const char *)&packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, (const char *)&packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_channel_io_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t configuration, uint8_t excitation, uint8_t version, uint8_t subversion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, configuration);
	_mav_put_uint8_t(buf, 2, excitation);
	_mav_put_uint8_t(buf, 3, version);
	_mav_put_uint8_t(buf, 4, subversion);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, buf, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
#else
	mavlink_channel_io_info_t *packet = (mavlink_channel_io_info_t *)msgbuf;
	packet->type = type;
	packet->configuration = configuration;
	packet->excitation = excitation;
	packet->version = version;
	packet->subversion = subversion;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, (const char *)packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN, MAVLINK_MSG_ID_CHANNEL_IO_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANNEL_IO_INFO, (const char *)packet, MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE CHANNEL_IO_INFO UNPACKING


/**
 * @brief Get field type from channel_io_info message
 *
 * @return Type of excitation: stepped sine, sweptsine, multisine,...
 */
static inline uint8_t mavlink_msg_channel_io_info_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field configuration from channel_io_info message
 *
 * @return Which inputs and outputs are selected. Choose one out of many default configurations
 */
static inline uint8_t mavlink_msg_channel_io_info_get_configuration(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field excitation from channel_io_info message
 *
 * @return Which channels where excited
 */
static inline uint8_t mavlink_msg_channel_io_info_get_excitation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field version from channel_io_info message
 *
 * @return log file version
 */
static inline uint8_t mavlink_msg_channel_io_info_get_version(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field subversion from channel_io_info message
 *
 * @return log file version
 */
static inline uint8_t mavlink_msg_channel_io_info_get_subversion(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a channel_io_info message into a struct
 *
 * @param msg The message to decode
 * @param channel_io_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_channel_io_info_decode(const mavlink_message_t* msg, mavlink_channel_io_info_t* channel_io_info)
{
#if MAVLINK_NEED_BYTE_SWAP
	channel_io_info->type = mavlink_msg_channel_io_info_get_type(msg);
	channel_io_info->configuration = mavlink_msg_channel_io_info_get_configuration(msg);
	channel_io_info->excitation = mavlink_msg_channel_io_info_get_excitation(msg);
	channel_io_info->version = mavlink_msg_channel_io_info_get_version(msg);
	channel_io_info->subversion = mavlink_msg_channel_io_info_get_subversion(msg);
#else
	memcpy(channel_io_info, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_CHANNEL_IO_INFO_LEN);
#endif
}
