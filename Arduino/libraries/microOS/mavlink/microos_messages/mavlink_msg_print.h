// MESSAGE PRINT PACKING

#define MAVLINK_MSG_ID_PRINT 5

typedef struct __mavlink_print_t
{
 char text[32]; ///< Text to be sent. We suggest termination with '\0'.
} mavlink_print_t;

#define MAVLINK_MSG_ID_PRINT_LEN 32
#define MAVLINK_MSG_ID_5_LEN 32

#define MAVLINK_MSG_ID_PRINT_CRC 107
#define MAVLINK_MSG_ID_5_CRC 107

#define MAVLINK_MSG_PRINT_FIELD_TEXT_LEN 32

#define MAVLINK_MESSAGE_INFO_PRINT { \
	"PRINT", \
	1, \
	{  { "text", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_print_t, text) }, \
         } \
}


/**
 * @brief Pack a print message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param text Text to be sent. We suggest termination with '\0'.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_print_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PRINT_LEN];

	_mav_put_char_array(buf, 0, text, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRINT_LEN);
#else
	mavlink_print_t packet;

	mav_array_memcpy(packet.text, text, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PRINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRINT_LEN);
#endif
}

/**
 * @brief Pack a print message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param text Text to be sent. We suggest termination with '\0'.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_print_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PRINT_LEN];

	_mav_put_char_array(buf, 0, text, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRINT_LEN);
#else
	mavlink_print_t packet;

	mav_array_memcpy(packet.text, text, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PRINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRINT_LEN);
#endif
}

/**
 * @brief Encode a print struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param print C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_print_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_print_t* print)
{
	return mavlink_msg_print_pack(system_id, component_id, msg, print->text);
}

/**
 * @brief Encode a print struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param print C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_print_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_print_t* print)
{
	return mavlink_msg_print_pack_chan(system_id, component_id, chan, msg, print->text);
}

/**
 * @brief Send a print message
 * @param chan MAVLink channel to send the message
 *
 * @param text Text to be sent. We suggest termination with '\0'.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_print_send(mavlink_channel_t chan, const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PRINT_LEN];

	_mav_put_char_array(buf, 0, text, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, buf, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, buf, MAVLINK_MSG_ID_PRINT_LEN);
#endif
#else
	mavlink_print_t packet;

	mav_array_memcpy(packet.text, text, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, (const char *)&packet, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, (const char *)&packet, MAVLINK_MSG_ID_PRINT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PRINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_print_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_char_array(buf, 0, text, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, buf, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, buf, MAVLINK_MSG_ID_PRINT_LEN);
#endif
#else
	mavlink_print_t *packet = (mavlink_print_t *)msgbuf;

	mav_array_memcpy(packet->text, text, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, (const char *)packet, MAVLINK_MSG_ID_PRINT_LEN, MAVLINK_MSG_ID_PRINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRINT, (const char *)packet, MAVLINK_MSG_ID_PRINT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PRINT UNPACKING


/**
 * @brief Get field text from print message
 *
 * @return Text to be sent. We suggest termination with '\0'.
 */
static inline uint16_t mavlink_msg_print_get_text(const mavlink_message_t* msg, char *text)
{
	return _MAV_RETURN_char_array(msg, text, 32,  0);
}

/**
 * @brief Decode a print message into a struct
 *
 * @param msg The message to decode
 * @param print C-struct to decode the message contents into
 */
static inline void mavlink_msg_print_decode(const mavlink_message_t* msg, mavlink_print_t* print)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_print_get_text(msg, print->text);
#else
	memcpy(print, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PRINT_LEN);
#endif
}
