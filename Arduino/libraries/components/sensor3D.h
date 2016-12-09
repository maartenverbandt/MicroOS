#ifndef SENSOR3D_H
#define SENSOR3D_H

#include "component_interface.h"

class Sensor3D : public ComponentInterface
{
private:
	int32_t _raw_value[3];
	int32_t _calibrated_value[3];
	float _scale[3];
	int32_t _offset[3];

public:
	Sensor3D(const uint8_t ID = 0);

	virtual int32_t* readRawValue();
	virtual int32_t* readCalibratedValue();
	int32_t* peekRawValue();
	int32_t* peekCalibratedValue();

	void setRawValue(int32_t raw_value_x, int32_t raw_value_y, int32_t raw_value_z);
	void setCalibratedValue(int32_t calibrated_value_x, int32_t calibrated_value_y, int32_t calibrated_value_z);

	void setScale(float scale_x, float scale_y, float scale_z);
	void setOffset(int32_t offset_x, int32_t offset_y, int32_t offset_z);
	float* getScale();
	int32_t* getOffset();

};

#endif //SENSOR3D
