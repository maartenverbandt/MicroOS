#ifndef ENCODER_SENSOR_H
#define ENCODER_SENSOR_H

#include "sensor1D.h"
#include "encoder.h"

class EncoderSensor : public Sensor1D
{
private:
	Encoder _encoder;

public:
	EncoderSensor(uint8_t pinA, uint8_t pinB, uint8_t ID = 0);

	bool init();

	int32_t readRawValue();
	float readCalibratedValue();
};

#endif //ENCODER_SENSOR_H
