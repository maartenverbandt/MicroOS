#include "pololuMD08A.h"

PololuMD08A::PololuMD08A(uint8_t pin_in1, uint8_t pin_pwm, Sensor1D *battery_voltage_sensor, uint8_t ID):
	HBridgeInterface(battery_voltage_sensor,ID), _pin_in1(pin_in1), _pin_in2(0xFF), _pin_pwm(pin_pwm)
{
	//do nothing
}

PololuMD08A::PololuMD08A(uint8_t pin_in1, uint8_t pin_pwm, int16_t battery_voltage, uint8_t ID):
	HBridgeInterface(battery_voltage, ID), _pin_in1(pin_in1), _pin_in2(0xFF), _pin_pwm(pin_pwm)
{
	//do nothing
}

PololuMD08A::PololuMD08A(uint8_t pin_in1, uint8_t pin_in2, uint8_t pin_pwm, Sensor1D *battery_voltage_sensor, uint8_t ID):
	HBridgeInterface(battery_voltage_sensor, ID), _pin_in1(pin_in1), _pin_in2(pin_in2), _pin_pwm(pin_pwm)
{
	//do nothing
}

PololuMD08A::PololuMD08A(uint8_t pin_in1, uint8_t pin_in2, uint8_t pin_pwm, int16_t battery_voltage, uint8_t ID):
	HBridgeInterface(battery_voltage, ID), _pin_in1(pin_in1), _pin_in2(pin_in2), _pin_pwm(pin_pwm)
{
	//do nothing
}

bool PololuMD08A::init()
{
	pinMode(_pin_in1,OUTPUT);
	// Check if the bridge is 1 or 2 pin controled
	if(_pin_in2 != 0xFF)
		pinMode(_pin_in2, OUTPUT);

#ifdef CORE_TEENSY
	analogWriteFrequency(_pin_pwm, 20000);	//increase pwm frequency to 20kHz
#endif

	return _battery_voltage_sensor->init();
}

void PololuMD08A::setOutputs()
{
	digitalWrite(_pin_in1, _polarity);
	if(_pin_in2 != 0xFF)
		digitalWrite(_pin_in2, !_polarity);
	analogWrite(_pin_pwm, _pwm);
}
