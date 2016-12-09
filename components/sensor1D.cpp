#include "sensor1D.h"

Sensor1D::Sensor1D(uint8_t ID) :
	ComponentInterface(ID), _raw_value(0), _calibrated_value(0), _scale(1.0f), _offset(0)
{
	//do nothing
}

int32_t Sensor1D::readRawValue()
{
	return _raw_value;
}

float Sensor1D::readCalibratedValue()
{
	_calibrated_value = (this->readRawValue() - _offset) * _scale;
	return _calibrated_value;
}

int32_t Sensor1D::peekRawValue()
{
	return _raw_value;
}

float Sensor1D::peekCalibratedValue()
{
	return _calibrated_value;
}

void Sensor1D::setRawValue(int32_t raw_value)
{
	_raw_value = raw_value;
}

void Sensor1D::setCalibratedValue(float calibrated_value)
{
	_calibrated_value = calibrated_value;
}

void Sensor1D::setScale(float scale)
{
	_scale = scale;
}

void Sensor1D::setOffset(int32_t offset)
{
	_offset = offset;
}

float Sensor1D::getScale()
{
	return _scale;
}

int32_t Sensor1D::getOffset()
{
	return _offset;
}
