#ifndef SENSOR1D_H
#define SENSOR1D_H

#include "component_interface.h"

class Sensor1D : public ComponentInterface
{
protected:
	int32_t _raw_value;
	float _calibrated_value;
	float _scale;
	int32_t _offset;

public:
	Sensor1D(uint8_t ID = 0);

	virtual int32_t readRawValue();
	virtual float readCalibratedValue();
	int32_t peekRawValue();
	float peekCalibratedValue();

	void setRawValue(int32_t raw_value);
	void setCalibratedValue(float calibrated_value);

	void setScale(float scale);
	void setOffset(int32_t offset);

	float getScale();
	int32_t getOffset();

};

#endif //SENSOR1D_H
