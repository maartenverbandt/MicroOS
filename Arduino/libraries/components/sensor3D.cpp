#include "sensor3D.h"

Sensor3D::Sensor3D(const uint8_t ID) :
	ComponentInterface(ID),
	_raw_value{0,0,0},
	_calibrated_value{0,0,0},
	_offset{0,0,0},
	_scale{1.0f,1.0f,1.0f}
{
	//do nothing
}

int32_t* Sensor3D::readRawValue()
{
	return _raw_value;
}

int32_t* Sensor3D::readCalibratedValue()
{
	this->readRawValue();
	for(uint8_t k=0;k<3;k++){
		_calibrated_value[k] = (_raw_value[k] - _offset[k]) * _scale[k];
	}
	return _calibrated_value;
}

int32_t* Sensor3D::peekRawValue()
{
	return _raw_value;
}

int32_t* Sensor3D::peekCalibratedValue()
{
	return _calibrated_value;
}

void Sensor3D::setRawValue(int32_t raw_value_x, int32_t raw_value_y, int32_t raw_value_z)
{
	_raw_value[0] = raw_value_x;
	_raw_value[1] = raw_value_y;
	_raw_value[2] = raw_value_z;
}

void Sensor3D::setCalibratedValue(int32_t calibrated_value_x, int32_t calibrated_value_y, int32_t calibrated_value_z)
{
	_calibrated_value[0] = calibrated_value_x;
	_calibrated_value[1] = calibrated_value_y;
	_calibrated_value[2] = calibrated_value_z;
}

void Sensor3D::setScale(float scale_x, float scale_y, float scale_z)
{
	_scale[0] = scale_x;
	_scale[1] = scale_y;
	_scale[2] = scale_z;
}

void Sensor3D::setOffset(int32_t offset_x, int32_t offset_y, int32_t offset_z)
{
	_offset[0] = offset_x;
	_offset[1] = offset_y;
	_offset[2] = offset_z;
}

float* Sensor3D::getScale()
{
	return _scale;
}

int32_t* Sensor3D::getOffset()
{
	return _offset;
}
