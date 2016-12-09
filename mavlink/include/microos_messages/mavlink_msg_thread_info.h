// MESSAGE THREAD_INFO PACKING

#define MAVLINK_MSG_ID_THREAD_INFO 1

typedef struct __mavlink_thread_info_t
{
 uint32_t time; ///< Onboard time.
 uint32_t total_duration; ///< total duration counter: used to compute the average duration [us].
 uint32_t total_latency; ///< total latency counter: used to compute the average latency [us].
 uint32_t number_of_executions; ///< number of executions of the thread.
 uint16_t duration; ///< get last duration [us].
 uint16_t latency; ///< get last latency [us].
 uint8_t ID; ///< Thread ID.
 uint8_t priority; ///< Get the priority of the thread.
} mavlink_thread_info_t;

#define MAVLINK_MSG_ID_THREAD_INFO_LEN 22
#define MAVLINK_MSG_ID_1_LEN 22

#define MAVLINK_MSG_ID_THREAD_INFO_CRC 215
#define MAVLINK_MSG_ID_1_CRC 215



#define MAVLINK_MESSAGE_INFO_THREAD_INFO { \
	"THREAD_INFO", \
	8, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_thread_info_t, time) }, \
         { "total_duration", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_thread_info_t, total_duration) }, \
         { "total_latency", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_thread_info_t, total_latency) }, \
         { "number_of_executions", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_thread_info_t, number_of_executions) }, \
         { "duration", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_thread_info_t, duration) }, \
         { "latency", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_thread_info_t, latency) }, \
         { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_thread_info_t, ID) }, \
         { "priority", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_thread_info_t, priority) }, \
         } \
}


/**
 * @brief Pack a thread_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time Onboard time.
 * @param ID Thread ID.
 * @param priority Get the priority of the thread.
 * @param duration get last duration [us].
 * @param latency get last latency [us].
 * @param total_duration total duration counter: used to compute the average duration [us].
 * @param total_latency total latency counter: used to compute the average latency [us].
 * @param number_of_executions number of executions of the thread.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_thread_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, uint8_t ID, uint8_t priority, uint16_t duration, uint16_t latency, uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_THREAD_INFO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint32_t(buf, 4, total_duration);
	_mav_put_uint32_t(buf, 8, total_latency);
	_mav_put_uint32_t(buf, 12, number_of_executions);
	_mav_put_uint16_t(buf, 16, duration);
	_mav_put_uint16_t(buf, 18, latency);
	_mav_put_uint8_t(buf, 20, ID);
	_mav_put_uint8_t(buf, 21, priority);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#else
	mavlink_thread_info_t packet;
	packet.time = time;
	packet.total_duration = total_duration;
	packet.total_latency = total_latency;
	packet.number_of_executions = number_of_executions;
	packet.duration = duration;
	packet.latency = latency;
	packet.ID = ID;
	packet.priority = priority;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_THREAD_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
}

/**
 * @brief Pack a thread_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Onboard time.
 * @param ID Thread ID.
 * @param priority Get the priority of the thread.
 * @param duration get last duration [us].
 * @param latency get last latency [us].
 * @param total_duration total duration counter: used to compute the average duration [us].
 * @param total_latency total latency counter: used to compute the average latency [us].
 * @param number_of_executions number of executions of the thread.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_thread_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,uint8_t ID,uint8_t priority,uint16_t duration,uint16_t latency,uint32_t total_duration,uint32_t total_latency,uint32_t number_of_executions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_THREAD_INFO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint32_t(buf, 4, total_duration);
	_mav_put_uint32_t(buf, 8, total_latency);
	_mav_put_uint32_t(buf, 12, number_of_executions);
	_mav_put_uint16_t(buf, 16, duration);
	_mav_put_uint16_t(buf, 18, latency);
	_mav_put_uint8_t(buf, 20, ID);
	_mav_put_uint8_t(buf, 21, priority);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#else
	mavlink_thread_info_t packet;
	packet.time = time;
	packet.total_duration = total_duration;
	packet.total_latency = total_latency;
	packet.number_of_executions = number_of_executions;
	packet.duration = duration;
	packet.latency = latency;
	packet.ID = ID;
	packet.priority = priority;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_THREAD_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
}

/**
 * @brief Encode a thread_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param thread_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_thread_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_thread_info_t* thread_info)
{
	return mavlink_msg_thread_info_pack(system_id, component_id, msg, thread_info->time, thread_info->ID, thread_info->priority, thread_info->duration, thread_info->latency, thread_info->total_duration, thread_info->total_latency, thread_info->number_of_executions);
}

/**
 * @brief Encode a thread_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param thread_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_thread_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_thread_info_t* thread_info)
{
	return mavlink_msg_thread_info_pack_chan(system_id, component_id, chan, msg, thread_info->time, thread_info->ID, thread_info->priority, thread_info->duration, thread_info->latency, thread_info->total_duration, thread_info->total_latency, thread_info->number_of_executions);
}

/**
 * @brief Send a thread_info message
 * @param chan MAVLink channel to send the message
 *
 * @param time Onboard time.
 * @param ID Thread ID.
 * @param priority Get the priority of the thread.
 * @param duration get last duration [us].
 * @param latency get last latency [us].
 * @param total_duration total duration counter: used to compute the average duration [us].
 * @param total_latency total latency counter: used to compute the average latency [us].
 * @param number_of_executions number of executions of the thread.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_thread_info_send(mavlink_channel_t chan, uint32_t time, uint8_t ID, uint8_t priority, uint16_t duration, uint16_t latency, uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_THREAD_INFO_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint32_t(buf, 4, total_duration);
	_mav_put_uint32_t(buf, 8, total_latency);
	_mav_put_uint32_t(buf, 12, number_of_executions);
	_mav_put_uint16_t(buf, 16, duration);
	_mav_put_uint16_t(buf, 18, latency);
	_mav_put_uint8_t(buf, 20, ID);
	_mav_put_uint8_t(buf, 21, priority);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, buf, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, buf, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
#else
	mavlink_thread_info_t packet;
	packet.time = time;
	packet.total_duration = total_duration;
	packet.total_latency = total_latency;
	packet.number_of_executions = number_of_executions;
	packet.duration = duration;
	packet.latency = latency;
	packet.ID = ID;
	packet.priority = priority;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, (const char *)&packet, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, (const char *)&packet, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_THREAD_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_thread_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, uint8_t ID, uint8_t priority, uint16_t duration, uint16_t latency, uint32_t total_duration, uint32_t total_latency, uint32_t number_of_executions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_uint32_t(buf, 4, total_duration);
	_mav_put_uint32_t(buf, 8, total_latency);
	_mav_put_uint32_t(buf, 12, number_of_executions);
	_mav_put_uint16_t(buf, 16, duration);
	_mav_put_uint16_t(buf, 18, latency);
	_mav_put_uint8_t(buf, 20, ID);
	_mav_put_uint8_t(buf, 21, priority);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, buf, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, buf, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
#else
	mavlink_thread_info_t *packet = (mavlink_thread_info_t *)msgbuf;
	packet->time = time;
	packet->total_duration = total_duration;
	packet->total_latency = total_latency;
	packet->number_of_executions = number_of_executions;
	packet->duration = duration;
	packet->latency = latency;
	packet->ID = ID;
	packet->priority = priority;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, (const char *)packet, MAVLINK_MSG_ID_THREAD_INFO_LEN, MAVLINK_MSG_ID_THREAD_INFO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_THREAD_INFO, (const char *)packet, MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE THREAD_INFO UNPACKING


/**
 * @brief Get field time from thread_info message
 *
 * @return Onboard time.
 */
static inline uint32_t mavlink_msg_thread_info_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field ID from thread_info message
 *
 * @return Thread ID.
 */
static inline uint8_t mavlink_msg_thread_info_get_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field priority from thread_info message
 *
 * @return Get the priority of the thread.
 */
static inline uint8_t mavlink_msg_thread_info_get_priority(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field duration from thread_info message
 *
 * @return get last duration [us].
 */
static inline uint16_t mavlink_msg_thread_info_get_duration(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field latency from thread_info message
 *
 * @return get last latency [us].
 */
static inline uint16_t mavlink_msg_thread_info_get_latency(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field total_duration from thread_info message
 *
 * @return total duration counter: used to compute the average duration [us].
 */
static inline uint32_t mavlink_msg_thread_info_get_total_duration(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field total_latency from thread_info message
 *
 * @return total latency counter: used to compute the average latency [us].
 */
static inline uint32_t mavlink_msg_thread_info_get_total_latency(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field number_of_executions from thread_info message
 *
 * @return number of executions of the thread.
 */
static inline uint32_t mavlink_msg_thread_info_get_number_of_executions(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a thread_info message into a struct
 *
 * @param msg The message to decode
 * @param thread_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_thread_info_decode(const mavlink_message_t* msg, mavlink_thread_info_t* thread_info)
{
#if MAVLINK_NEED_BYTE_SWAP
	thread_info->time = mavlink_msg_thread_info_get_time(msg);
	thread_info->total_duration = mavlink_msg_thread_info_get_total_duration(msg);
	thread_info->total_latency = mavlink_msg_thread_info_get_total_latency(msg);
	thread_info->number_of_executions = mavlink_msg_thread_info_get_number_of_executions(msg);
	thread_info->duration = mavlink_msg_thread_info_get_duration(msg);
	thread_info->latency = mavlink_msg_thread_info_get_latency(msg);
	thread_info->ID = mavlink_msg_thread_info_get_ID(msg);
	thread_info->priority = mavlink_msg_thread_info_get_priority(msg);
#else
	memcpy(thread_info, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_THREAD_INFO_LEN);
#endif
}
