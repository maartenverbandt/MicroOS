#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ComponentInterface
{
private:
	const uint8_t _ID;
	
public:
	ComponentInterface(uint8_t ID = 0) :
		_ID(ID)
	{
		//do nothing
	}

	uint8_t ID(){ return _ID; }
	virtual bool init(){ return true; }

};

#endif //COMPONENT_INTERFACE_H
