#include "stepper.h"

Stepper::Stepper(uint8_t ID):
	ComponentInterface(ID),
	_position(0x80000000),
	_speed(0.0f),
	_position_integrator(0.0f)
{
	_last_update = micros();
}

int Stepper::position()
{
	return (int)((long)_position - (long)0x80000000);
}

void Stepper::setSpeed(float speed)
{
	_speed = speed;
}

int Stepper::update()
{
	unsigned long _time = micros();
	float _dt = (_time - _last_update)/1000000.0f;
	_last_update = _time;
	
	return this->update(_dt);
}

int Stepper::update(float _dt)
{
	_position_integrator += _dt*_speed;
	
	while(_position_integrator>=1.0f){
		this->stepCW();
		_position_integrator -= 1.0f;
	}
	while(_position_integrator<=-1.0f){
		this->stepCCW();
		_position_integrator += 1.0f;
	}
	
	return this->position();
}
