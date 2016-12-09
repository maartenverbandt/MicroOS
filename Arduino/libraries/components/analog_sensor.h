#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "sensor1D.h"

class AnalogSensor : public Sensor1D
{
private:
	const uint8_t _pin; //analog pin to read the value from

public:
	AnalogSensor(uint8_t pin = 255, uint8_t ID = 0);

	bool init();
	int32_t readRawValue();
};

#endif //ANALOG_SENSOR_H
