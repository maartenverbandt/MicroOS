#ifndef COMMUNICATOR_CONFIG_H
#define COMMUNICATOR_CONFIG_H

//define the number of channels, such that _channels[i] become available
#define NUM_COMM_PORTS	1

//define which serial port to use 
#define COMM_PORTA		Serial
//define the baud rate
#define COMM_PORTA_BAUD	115200

//define the number of messages to be transmitted continuously
#define NUM_UPDATE_MESSAGES 1
//define transmission wakeup period in [us]. The messages will be send with a frequency of NUM_UPDATE_MESSAGES/TRANS_WAKEUP
#define TRANS_WAKEUP		10000		
//define the receive wakeup period in [us]. The incoming buffer is emptied at once
#define RECV_WAKEUP			100000
//define the heartbeat transmission period in [us].
#define HEARTBEAT_WAKEUP	1000000
//define log message frequency.. Not in this example
#define LOG_WAKEUP			10000

#endif //COMMUNICATOR_CONFIG_H
