#ifndef STEPPER_H
#define STEPPER_H

#include "component_interface.h"

class Stepper : public ComponentInterface
{
private:	
	float	 		_speed;
	float			_position_integrator;
	unsigned long	_last_update;

protected:
	uint32_t _position;

public:
	Stepper(uint8_t ID = 0);

	int position();
	
	void setSpeed(float speed);				//speed in steps per second    	
	
	virtual void stepCW() = 0;
	virtual void stepCCW() = 0;
    int update();
    int update(float _dt);
};

#endif //STEPPER_H
