#include "difference_sensor.h"

DifferenceSensor::DifferenceSensor(Sensor1D* sensor, uint8_t ID, float alpha) :
	Sensor1D(ID), _sensor(sensor), _raw_value_old(0), _alpha(alpha)
{
	_last_update = micros();

	// Set calibration of the difference sensor
	_offset = 0;
	_scale = _sensor->getScale();
}

int32_t DifferenceSensor::readRawValue()
{
	int32_t raw_value_new = _sensor->readRawValue();
	uint32_t time = micros();

	// caluculate the finite difference
	//_raw_value = ((raw_value_new - _raw_value_old)*1000000)/(time-_last_update);
	_raw_value = (1.0-_alpha)*_raw_value + _alpha*((raw_value_new - _raw_value_old)*1000000.0)/(time-_last_update);

	_last_update = time;
	_raw_value_old = raw_value_new;

	return _raw_value;
}
