#include "encoder_sensor.h"

EncoderSensor::EncoderSensor(uint8_t pinA, uint8_t pinB, uint8_t ID) :
	Sensor1D(ID), _encoder(pinA,pinB)
{
	//do nothing
}

bool EncoderSensor::init()
{
	_encoder.write(0); //initialize the encoder value to 0
}

/**
 * Reads the raw encoder value
 */

int32_t EncoderSensor::readRawValue()
{
	_raw_value = _encoder.read();
	_calibrated_value = _raw_value;
	return _raw_value;
}

/**
 * Reads the calibrated encoder value which is always equal to the raw value. Calling this function is less efficient than calling readRawValue(). This function is implemented for sake of completeness.
 */

float EncoderSensor::readCalibratedValue()
{
	return this->readRawValue();
}
