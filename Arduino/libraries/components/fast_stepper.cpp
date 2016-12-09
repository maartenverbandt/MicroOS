#include "fast_stepper.h"

FastStepper::FastStepper(uint8_t ID) : ComponentInterface(ID), _position(0.0f), _speed(0.0f), _acceleration(0.0f)
{
	_last_update = micros();
}

//int position();
//float speed()
//float acceleration();

void FastStepper::setSpeed(float speed)
{
	_speed = speed;
}

void FastStepper::setAcceleration(float acceleration)
{
	_acceleration = acceleration;
}

/*virtual void stepCW() = 0;
virtual void stepCCW() = 0;*/

int FastStepper::update()
{
	unsigned long _time = micros();
	float _dt = (_time - _last_update)*0.000001f;
	_last_update = _time;
	
	return this->update(_dt);
}

int FastStepper::update(float _dt)
{
	_speed += (_dt*_acceleration);
	_position += (_dt*_speed); // + 0.5f*_dt*_acceleration);
	
	return _position;
}


uint16_t FastStepper::getTimerCompare(uint32_t frequency)
{
	float abs_speed = (_speed>0?_speed:-_speed);
	uint32_t compare = (frequency - abs_speed)/abs_speed;
	if(compare > 0xFFFF){
		compare = 0xFFFF;
	}
	
	return compare;
}

float FastStepper::position()
{
	return _position;
}

float FastStepper::speed()
{
	return _speed;
}

float FastStepper::acceleration()
{
	return _acceleration;
}
