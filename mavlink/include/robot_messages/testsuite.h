/** @file
 *	@brief MAVLink comm protocol testsuite generated from robot_messages.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef ROBOT_MESSAGES_TESTSUITE_H
#define ROBOT_MESSAGES_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_microos_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_robot_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_microos_messages(system_id, component_id, last_msg);
	mavlink_test_robot_messages(system_id, component_id, last_msg);
}
#endif

#include "../microos_messages/testsuite.h"


static void mavlink_test_pose(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_pose_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}17859,
	}17963,
	}18067,
	};
	mavlink_pose_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.x = packet_in.x;
        	packet1.y = packet_in.y;
        	packet1.z = packet_in.z;
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_send(MAVLINK_COMM_1 , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_attitude(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_attitude_t packet_in = {
		963497464,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	}18067,
	}18171,
	}18275,
	}18379,
	}18483,
	}18587,
	};
	mavlink_attitude_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.roll_cmd = packet_in.roll_cmd;
        	packet1.pitch_cmd = packet_in.pitch_cmd;
        	packet1.yaw_cmd = packet_in.yaw_cmd;
        	packet1.roll_act = packet_in.roll_act;
        	packet1.pitch_act = packet_in.pitch_act;
        	packet1.yaw_act = packet_in.yaw_act;
        	packet1.roll_cont = packet_in.roll_cont;
        	packet1.pitch_cont = packet_in.pitch_cont;
        	packet1.yaw_cont = packet_in.yaw_cont;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_pack(system_id, component_id, &msg , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_cmd , packet1.pitch_cmd , packet1.yaw_cmd , packet1.roll_act , packet1.pitch_act , packet1.yaw_act , packet1.roll_cont , packet1.pitch_cont , packet1.yaw_cont );
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_cmd , packet1.pitch_cmd , packet1.yaw_cmd , packet1.roll_act , packet1.pitch_act , packet1.yaw_act , packet1.roll_cont , packet1.pitch_cont , packet1.yaw_cont );
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_send(MAVLINK_COMM_1 , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_cmd , packet1.pitch_cmd , packet1.yaw_cmd , packet1.roll_act , packet1.pitch_act , packet1.yaw_act , packet1.roll_cont , packet1.pitch_cont , packet1.yaw_cont );
	mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_velocity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_velocity_t packet_in = {
		963497464,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	}18067,
	}18171,
	}18275,
	}18379,
	}18483,
	}18587,
	};
	mavlink_velocity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.vx = packet_in.vx;
        	packet1.vy = packet_in.vy;
        	packet1.vz = packet_in.vz;
        	packet1.vx_cmd = packet_in.vx_cmd;
        	packet1.vy_cmd = packet_in.vy_cmd;
        	packet1.vz_cmd = packet_in.vz_cmd;
        	packet1.vx_act = packet_in.vx_act;
        	packet1.vy_act = packet_in.vy_act;
        	packet1.vz_act = packet_in.vz_act;
        	packet1.vx_cont = packet_in.vx_cont;
        	packet1.vy_cont = packet_in.vy_cont;
        	packet1.vz_cont = packet_in.vz_cont;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_pack(system_id, component_id, &msg , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_cmd , packet1.vy_cmd , packet1.vz_cmd , packet1.vx_act , packet1.vy_act , packet1.vz_act , packet1.vx_cont , packet1.vy_cont , packet1.vz_cont );
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_cmd , packet1.vy_cmd , packet1.vz_cmd , packet1.vx_act , packet1.vy_act , packet1.vz_act , packet1.vx_cont , packet1.vy_cont , packet1.vz_cont );
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_send(MAVLINK_COMM_1 , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_cmd , packet1.vy_cmd , packet1.vz_cmd , packet1.vx_act , packet1.vy_act , packet1.vz_act , packet1.vx_cont , packet1.vy_cont , packet1.vz_cont );
	mavlink_msg_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_position_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}963498088,
	}963498296,
	}963498504,
	}963498712,
	}18691,
	}18795,
	}18899,
	}19003,
	}19107,
	}19211,
	};
	mavlink_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.x = packet_in.x;
        	packet1.y = packet_in.y;
        	packet1.z = packet_in.z;
        	packet1.x_cmd = packet_in.x_cmd;
        	packet1.y_cmd = packet_in.y_cmd;
        	packet1.z_cmd = packet_in.z_cmd;
        	packet1.x_act = packet_in.x_act;
        	packet1.y_act = packet_in.y_act;
        	packet1.z_act = packet_in.z_act;
        	packet1.x_cont = packet_in.x_cont;
        	packet1.y_cont = packet_in.y_cont;
        	packet1.z_cont = packet_in.z_cont;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_pack(system_id, component_id, &msg , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_cmd , packet1.y_cmd , packet1.z_cmd , packet1.x_act , packet1.y_act , packet1.z_act , packet1.x_cont , packet1.y_cont , packet1.z_cont );
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_cmd , packet1.y_cmd , packet1.z_cmd , packet1.x_act , packet1.y_act , packet1.z_act , packet1.x_cont , packet1.y_cont , packet1.z_cont );
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_send(MAVLINK_COMM_1 , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_cmd , packet1.y_cmd , packet1.z_cmd , packet1.x_act , packet1.y_act , packet1.z_act , packet1.x_cont , packet1.y_cont , packet1.z_cont );
	mavlink_msg_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_attitude_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_attitude_cmd_t packet_in = {
		17235,
	}17339,
	}17443,
	}17547,
	}17651,
	}17755,
	};
	mavlink_attitude_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.rollFF = packet_in.rollFF;
        	packet1.pitchFF = packet_in.pitchFF;
        	packet1.yawFF = packet_in.yawFF;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_cmd_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_attitude_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_cmd_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollFF , packet1.pitchFF , packet1.yawFF );
	mavlink_msg_attitude_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollFF , packet1.pitchFF , packet1.yawFF );
	mavlink_msg_attitude_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_attitude_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_cmd_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollFF , packet1.pitchFF , packet1.yawFF );
	mavlink_msg_attitude_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_velocity_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_velocity_cmd_t packet_in = {
		17235,
	}17339,
	}17443,
	}17547,
	}17651,
	}17755,
	};
	mavlink_velocity_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.vx = packet_in.vx;
        	packet1.vy = packet_in.vy;
        	packet1.vz = packet_in.vz;
        	packet1.vxFF = packet_in.vxFF;
        	packet1.vyFF = packet_in.vyFF;
        	packet1.vzFF = packet_in.vzFF;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_cmd_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_velocity_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_cmd_pack(system_id, component_id, &msg , packet1.vx , packet1.vy , packet1.vz , packet1.vxFF , packet1.vyFF , packet1.vzFF );
	mavlink_msg_velocity_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vx , packet1.vy , packet1.vz , packet1.vxFF , packet1.vyFF , packet1.vzFF );
	mavlink_msg_velocity_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_velocity_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_cmd_send(MAVLINK_COMM_1 , packet1.vx , packet1.vy , packet1.vz , packet1.vxFF , packet1.vyFF , packet1.vzFF );
	mavlink_msg_velocity_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_position_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_position_cmd_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}17859,
	}17963,
	}18067,
	};
	mavlink_position_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.x = packet_in.x;
        	packet1.y = packet_in.y;
        	packet1.z = packet_in.z;
        	packet1.xFF = packet_in.xFF;
        	packet1.yFF = packet_in.yFF;
        	packet1.zFF = packet_in.zFF;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_cmd_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_position_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_cmd_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.xFF , packet1.yFF , packet1.zFF );
	mavlink_msg_position_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.xFF , packet1.yFF , packet1.zFF );
	mavlink_msg_position_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_position_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_cmd_send(MAVLINK_COMM_1 , packet1.x , packet1.y , packet1.z , packet1.xFF , packet1.yFF , packet1.zFF );
	mavlink_msg_position_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_radar_cloud(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_radar_cloud_t packet_in = {
		{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469 },
	}{ 963498712, 963498713, 963498714, 963498715, 963498716, 963498717 },
	};
	mavlink_radar_cloud_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        	mav_array_memcpy(packet1.x, packet_in.x, sizeof(int32_t)*6);
        	mav_array_memcpy(packet1.y, packet_in.y, sizeof(int32_t)*6);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_pack(system_id, component_id, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_radar_cloud_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_send(MAVLINK_COMM_1 , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_radar_line(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_radar_line_t packet_in = {
		{ 963497464, 963497465 },
	}{ 963497880, 963497881 },
	};
	mavlink_radar_line_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        	mav_array_memcpy(packet1.x, packet_in.x, sizeof(int32_t)*2);
        	mav_array_memcpy(packet1.y, packet_in.y, sizeof(int32_t)*2);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_pack(system_id, component_id, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_radar_line_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_send(MAVLINK_COMM_1 , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_signal_sweptsine(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_signal_sweptsine_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}18067,
	};
	mavlink_signal_sweptsine_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.fmin = packet_in.fmin;
        	packet1.fmax = packet_in.fmax;
        	packet1.period = packet_in.period;
        	packet1.amplitude = packet_in.amplitude;
        	packet1.channels = packet_in.channels;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_sweptsine_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_signal_sweptsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_sweptsine_pack(system_id, component_id, &msg , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.amplitude );
	mavlink_msg_signal_sweptsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_sweptsine_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.amplitude );
	mavlink_msg_signal_sweptsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_signal_sweptsine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_sweptsine_send(MAVLINK_COMM_1 , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.amplitude );
	mavlink_msg_signal_sweptsine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_signal_multisine(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_signal_multisine_t packet_in = {
		17.0,
	}17443,
	}151,
	};
	mavlink_signal_multisine_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.amplitude = packet_in.amplitude;
        	packet1.channels = packet_in.channels;
        	packet1.id = packet_in.id;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_multisine_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_signal_multisine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_multisine_pack(system_id, component_id, &msg , packet1.channels , packet1.id , packet1.amplitude );
	mavlink_msg_signal_multisine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_multisine_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.channels , packet1.id , packet1.amplitude );
	mavlink_msg_signal_multisine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_signal_multisine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_multisine_send(MAVLINK_COMM_1 , packet1.channels , packet1.id , packet1.amplitude );
	mavlink_msg_signal_multisine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_signal_steppedsine(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_signal_steppedsine_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}18067,
	}187,
	};
	mavlink_signal_steppedsine_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.fmin = packet_in.fmin;
        	packet1.fmax = packet_in.fmax;
        	packet1.stepsize = packet_in.stepsize;
        	packet1.amplitude = packet_in.amplitude;
        	packet1.channels = packet_in.channels;
        	packet1.period = packet_in.period;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_steppedsine_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_signal_steppedsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_steppedsine_pack(system_id, component_id, &msg , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.stepsize , packet1.amplitude );
	mavlink_msg_signal_steppedsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_steppedsine_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.stepsize , packet1.amplitude );
	mavlink_msg_signal_steppedsine_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_signal_steppedsine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_signal_steppedsine_send(MAVLINK_COMM_1 , packet1.channels , packet1.fmin , packet1.fmax , packet1.period , packet1.stepsize , packet1.amplitude );
	mavlink_msg_signal_steppedsine_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_channel_io(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_channel_io_t packet_in = {
		963497464,
	}{ 45.0, 46.0, 47.0, 48.0, 49.0, 50.0 },
	}{ 213.0, 214.0, 215.0, 216.0, 217.0, 218.0 },
	}161,
	};
	mavlink_channel_io_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.sync = packet_in.sync;
        
        	mav_array_memcpy(packet1.input, packet_in.input, sizeof(float)*6);
        	mav_array_memcpy(packet1.output, packet_in.output, sizeof(float)*6);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_pack(system_id, component_id, &msg , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_channel_io_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_send(MAVLINK_COMM_1 , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_channel_io_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_channel_io_info_t packet_in = {
		5,
	}72,
	}139,
	}206,
	}17,
	};
	mavlink_channel_io_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.type = packet_in.type;
        	packet1.configuration = packet_in.configuration;
        	packet1.excitation = packet_in.excitation;
        	packet1.version = packet_in.version;
        	packet1.subversion = packet_in.subversion;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_pack(system_id, component_id, &msg , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_channel_io_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_send(MAVLINK_COMM_1 , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_robot_messages(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_pose(system_id, component_id, last_msg);
	mavlink_test_attitude(system_id, component_id, last_msg);
	mavlink_test_velocity(system_id, component_id, last_msg);
	mavlink_test_position(system_id, component_id, last_msg);
	mavlink_test_attitude_cmd(system_id, component_id, last_msg);
	mavlink_test_velocity_cmd(system_id, component_id, last_msg);
	mavlink_test_position_cmd(system_id, component_id, last_msg);
	mavlink_test_radar_cloud(system_id, component_id, last_msg);
	mavlink_test_radar_line(system_id, component_id, last_msg);
	mavlink_test_signal_sweptsine(system_id, component_id, last_msg);
	mavlink_test_signal_multisine(system_id, component_id, last_msg);
	mavlink_test_signal_steppedsine(system_id, component_id, last_msg);
	mavlink_test_channel_io(system_id, component_id, last_msg);
	mavlink_test_channel_io_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ROBOT_MESSAGES_TESTSUITE_H
