#ifndef SHARP41S_H
#define SHARP41S_H

#include "analog_sensor.h"

class Sharp41S: public AnalogSensor
{
public:
	Sharp41S(uint8_t pin, uint8_t ID = 0);

	float readCalibratedValue();
};

#endif //SHARP41S_H
