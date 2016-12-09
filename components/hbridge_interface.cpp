#include "hbridge_interface.h"

HBridgeInterface::HBridgeInterface(Sensor1D *battery_voltage_sensor, uint8_t ID) :
	ComponentInterface(ID), _battery_voltage_sensor(battery_voltage_sensor)
{
	//do nothing
}

HBridgeInterface::HBridgeInterface(int16_t battery_voltage, uint8_t ID) :
	ComponentInterface(ID), _battery_voltage_sensor(new Sensor1D)
{
	_battery_voltage_sensor->setRawValue(battery_voltage);
	_battery_voltage_sensor->setCalibratedValue(battery_voltage);
}

bool HBridgeInterface::init()
{
	_battery_voltage_sensor->init();
	setBridgeVoltage(0);

	return true;
}

void HBridgeInterface::setBridgeVoltage(int16_t bridge_voltage)
{
	uint32_t battery_voltage = _battery_voltage_sensor->peekCalibratedValue();
	_polarity = (bridge_voltage>=0);

	if(!_polarity){
		bridge_voltage = -bridge_voltage;
	}
	_pwm = (bridge_voltage<battery_voltage?((uint32_t)bridge_voltage*255)/battery_voltage:255);

	setOutputs(); //write settings to bridge pins
}

void HBridgeInterface::setPolarity(bool polarity)
{
	_polarity = polarity;
}

void HBridgeInterface::setPWM(uint8_t pwm)
{
	_pwm = pwm;
}

Sensor1D* HBridgeInterface::batteryVoltageSensor()
{
	return _battery_voltage_sensor;
}

int16_t HBridgeInterface::getBridgeVoltage()
{
	int16_t bridge_voltage = (_battery_voltage_sensor->peekCalibratedValue()*_pwm)/255;
	if(_polarity)
		return bridge_voltage;
	else
		return -bridge_voltage;
}

bool HBridgeInterface::getPolarity()
{
	return _polarity;
}

int16_t HBridgeInterface::getPWM()
{
	return _pwm;
}
