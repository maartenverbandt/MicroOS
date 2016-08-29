#include "channel.h"
#include "microOS.h"

Channel::Channel(Stream *port, ProtocolInterface *protocol) :
	 _active(false), _port(port), _protocol(protocol)
{
	//do nothing
}

void Channel::start()
{
	if((_port!=NULL) && (_protocol!=NULL))
		_active = true;
}

void Channel::stop()
{
	_active = false;
}

bool Channel::receive()
{
	if(_active){
		bool msg_flag = false;
		while((_port->available())&&(!msg_flag)){		//keep on receiving bytes until we find a message or all bytes are read
			msg_flag = _protocol->decode(_port->read());//set the message flag to received status
		}
		return msg_flag;
	} else {
		return false;
	}
}

bool Channel::send(void *msg)
{
	if(_active){
		uint8_t buffer[CHANNEL_BUFFER_SIZE];
		uint16_t length = _protocol->encode(msg, buffer);
		return (_port->write(buffer, length) == length);
	} else {
		return false;
	}
}

bool Channel::getActive(){ return _active; }
Stream* Channel::getPort(){ return _port; }
ProtocolInterface* Channel::getProtocol(){ return _protocol; }
void* Channel::getMessage(){ return _protocol->getMessage(); }
