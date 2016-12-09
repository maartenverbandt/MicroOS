#include "sharp41S.h"

Sharp41S::Sharp41S(uint8_t pin, uint8_t ID):
	AnalogSensor(pin,ID)
{
	//do nothing special
}

float Sharp41S::readCalibratedValue()
{
	//do custom non-linear calibration of the analog sensor
	// Calibration provided by Ruben: calib = 24.7694/raw + 0.0109311 (Updated by Armin)
	
	_calibrated_value = 24.7694f/this->readRawValue() + 0.0109311f;
}
