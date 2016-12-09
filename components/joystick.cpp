#include "joystick.h"

Joystick::Joystick(uint8_t pin_x, uint8_t pin_y, uint8_t ID) :
	ComponentInterface(ID),
	_x(pin_x, ID),
	_y(pin_y, ID)
{
	setAnalogReadResolution(10); //set arduino's standard 10 bit resolution
}

bool Joystick::init()
{
	return (_x.init() && _y.init());
}

float Joystick::getX()
{
	return _x.readCalibratedValue();
}

float Joystick::getY()
{
	return _y.readCalibratedValue();
}

void Joystick::setAnalogReadResolution(uint8_t bits)
{
	int offset = 1 << (bits - 1); //
	float scale = 1.0f/offset;

	_x.setOffset(offset);
	_y.setOffset(offset);
	_x.setScale(scale);
	_y.setScale(scale);
}
