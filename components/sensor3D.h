#ifndef SENSOR3D_H
#define SENSOR3D_H

#include "component_interface.h"

class Sensor3D : public ComponentInterface
{
private:
	int _raw_value[3];
	int _calibrated_value[3];
	float _scale[3];
	int _offset[3];
	
public:
	Sensor3D(const uint8_t ID = 0);

	virtual int* readRawValue();
	virtual int* readCalibratedValue();
	int* peekRawValue();
	int* peekCalibratedValue();

	void setRawValue(int raw_value_x, int raw_value_y, int raw_value_z);
	void setCalibratedValue(int calibrated_value_x, int calibrated_value_y, int calibrated_value_z);

	void setScale(float scale_x, float scale_y, float scale_z);
	void setOffset(int offset_x, int offset_y, int offset_z);
	float* getScale();
	int* getOffset();

};

#endif //SENSOR3D
