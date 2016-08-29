#include "analog_sensor.h"

AnalogSensor::AnalogSensor(uint8_t pin, uint8_t ID) :
	Sensor1D(ID), _pin(pin)
{
	//do nothing
}

bool AnalogSensor::init()
{
	pinMode(_pin, INPUT);
	this->readCalibratedValue();

	return true;
}

int32_t AnalogSensor::readRawValue()
{
	_raw_value = analogRead(_pin);
	return _raw_value;
}
