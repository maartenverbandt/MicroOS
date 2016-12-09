#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "component_interface.h"
#include "analog_sensor.h"

class Joystick : public ComponentInterface
{
private:
	AnalogSensor _x;
	AnalogSensor _y;

public:
	Joystick(uint8_t pin_x, uint8_t pin_y, uint8_t ID = 255);
	bool init();

	float getX();
	float getY();

	void setAnalogReadResolution(uint8_t bits);
};

#endif
