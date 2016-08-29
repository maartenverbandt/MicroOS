#ifndef FAST_STEPPER_H
#define FAST_STEPPER_H

#include "component_interface.h"

class FastStepper : public ComponentInterface
{
private:	
	float			_position;
	float	 		_speed;
	float			_acceleration;
	float			_position_integrator;
	unsigned long	_last_update;

public:
	FastStepper(uint8_t ID = 0);

	float position();
	float speed();
	float acceleration();
	
	void setSpeed(float speed);					//speed in steps per second    	
	void setAcceleration(float acceleration);	//acceleration in steps per second
	
	/*virtual void stepCW() = 0;
	virtual void stepCCW() = 0;*/
    int update();
    int update(float _dt);
    
    uint16_t getTimerCompare(uint32_t frequency);
};

#endif //FAST_STEPPER_H
