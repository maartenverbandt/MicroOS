/** @file
 *	@brief MAVLink comm protocol testsuite generated from microos_messages.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef MICROOS_MESSAGES_TESTSUITE_H
#define MICROOS_MESSAGES_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_microos_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_microos_messages(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_heartbeat_t packet_in = {
		963497464,
	}17,
	}{ 84, 85, 86, 87, 88, 89, 90, 91 },
	}2,
	};
	mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.type = packet_in.type;
        	packet1.mavlink_version = packet_in.mavlink_version;
        
        	mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*8);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.type , packet1.time , packet1.data );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.time , packet1.data );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.type , packet1.time , packet1.data );
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_thread_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_thread_info_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}963498088,
	}18067,
	}18171,
	}65,
	}132,
	};
	mavlink_thread_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.total_duration = packet_in.total_duration;
        	packet1.total_latency = packet_in.total_latency;
        	packet1.number_of_executions = packet_in.number_of_executions;
        	packet1.duration = packet_in.duration;
        	packet1.latency = packet_in.latency;
        	packet1.ID = packet_in.ID;
        	packet1.priority = packet_in.priority;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_thread_info_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_thread_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_thread_info_pack(system_id, component_id, &msg , packet1.time , packet1.ID , packet1.priority , packet1.duration , packet1.latency , packet1.total_duration , packet1.total_latency , packet1.number_of_executions );
	mavlink_msg_thread_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_thread_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.ID , packet1.priority , packet1.duration , packet1.latency , packet1.total_duration , packet1.total_latency , packet1.number_of_executions );
	mavlink_msg_thread_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_thread_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_thread_info_send(MAVLINK_COMM_1 , packet1.time , packet1.ID , packet1.priority , packet1.duration , packet1.latency , packet1.total_duration , packet1.total_latency , packet1.number_of_executions );
	mavlink_msg_thread_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_partition(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_partition_t packet_in = {
		17235,
	}'C',
	}206,
	}17,
	}{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115 },
	};
	mavlink_partition_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.index = packet_in.index;
        	packet1.ID = packet_in.ID;
        	packet1.size = packet_in.size;
        	packet1.togo = packet_in.togo;
        
        	mav_array_memcpy(packet1.value, packet_in.value, sizeof(uint8_t)*32);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_partition_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_partition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_partition_pack(system_id, component_id, &msg , packet1.ID , packet1.index , packet1.size , packet1.togo , packet1.value );
	mavlink_msg_partition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_partition_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.index , packet1.size , packet1.togo , packet1.value );
	mavlink_msg_partition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_partition_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_partition_send(MAVLINK_COMM_1 , packet1.ID , packet1.index , packet1.size , packet1.togo , packet1.value );
	mavlink_msg_partition_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gpio(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gpio_t packet_in = {
		963497464,
	}{ 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0 },
	}{ 963499336, 963499337, 963499338, 963499339 },
	};
	mavlink_gpio_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        
        	mav_array_memcpy(packet1.gpio_float, packet_in.gpio_float, sizeof(float)*8);
        	mav_array_memcpy(packet1.gpio_int, packet_in.gpio_int, sizeof(int32_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gpio_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gpio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gpio_pack(system_id, component_id, &msg , packet1.time , packet1.gpio_float , packet1.gpio_int );
	mavlink_msg_gpio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gpio_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.gpio_float , packet1.gpio_int );
	mavlink_msg_gpio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gpio_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gpio_send(MAVLINK_COMM_1 , packet1.time , packet1.gpio_float , packet1.gpio_int );
	mavlink_msg_gpio_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_event(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_event_t packet_in = {
		17235,
	};
	mavlink_event_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.type = packet_in.type;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_event_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_event_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_event_pack(system_id, component_id, &msg , packet1.type );
	mavlink_msg_event_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_event_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type );
	mavlink_msg_event_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_event_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_event_send(MAVLINK_COMM_1 , packet1.type );
	mavlink_msg_event_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_print(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_print_t packet_in = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE",
	};
	mavlink_print_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        	mav_array_memcpy(packet1.text, packet_in.text, sizeof(char)*32);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_print_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_print_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_print_pack(system_id, component_id, &msg , packet1.text );
	mavlink_msg_print_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_print_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.text );
	mavlink_msg_print_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_print_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_print_send(MAVLINK_COMM_1 , packet1.text );
	mavlink_msg_print_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_param_int(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_param_int_t packet_in = {
		963497464,
	}17443,
	}'G',
	}"HIJKLMN",
	};
	mavlink_param_int_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.value = packet_in.value;
        	packet1.pointer = packet_in.pointer;
        	packet1.ID = packet_in.ID;
        
        	mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*8);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_int_pack(system_id, component_id, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_int_send(MAVLINK_COMM_1 , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_param_float(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_param_float_t packet_in = {
		17.0,
	}17443,
	}'G',
	}"HIJKLMN",
	};
	mavlink_param_float_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.value = packet_in.value;
        	packet1.pointer = packet_in.pointer;
        	packet1.ID = packet_in.ID;
        
        	mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*8);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_float_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_float_pack(system_id, component_id, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_float_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_float_send(MAVLINK_COMM_1 , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_param_string(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_param_string_t packet_in = {
		17235,
	}'C',
	}"DEFGHIJ",
	}"LMNOPQRSTUVWXYZABCDEFGHIJKLMNOP",
	};
	mavlink_param_string_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.pointer = packet_in.pointer;
        	packet1.ID = packet_in.ID;
        
        	mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*8);
        	mav_array_memcpy(packet1.value, packet_in.value, sizeof(char)*32);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_string_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_string_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_string_pack(system_id, component_id, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_string_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_string_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_string_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_string_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_string_send(MAVLINK_COMM_1 , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_string_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_param_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_param_data_t packet_in = {
		17235,
	}'C',
	}"DEFGHIJ",
	}{ 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5 },
	};
	mavlink_param_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.pointer = packet_in.pointer;
        	packet1.ID = packet_in.ID;
        
        	mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*8);
        	mav_array_memcpy(packet1.value, packet_in.value, sizeof(uint8_t)*32);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_data_pack(system_id, component_id, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_param_data_send(MAVLINK_COMM_1 , packet1.ID , packet1.pointer , packet1.name , packet1.value );
	mavlink_msg_param_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_microos_messages(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_heartbeat(system_id, component_id, last_msg);
	mavlink_test_thread_info(system_id, component_id, last_msg);
	mavlink_test_partition(system_id, component_id, last_msg);
	mavlink_test_gpio(system_id, component_id, last_msg);
	mavlink_test_event(system_id, component_id, last_msg);
	mavlink_test_print(system_id, component_id, last_msg);
	mavlink_test_param_int(system_id, component_id, last_msg);
	mavlink_test_param_float(system_id, component_id, last_msg);
	mavlink_test_param_string(system_id, component_id, last_msg);
	mavlink_test_param_data(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MICROOS_MESSAGES_TESTSUITE_H
