#ifndef POLOLUMD08A_H
#define POLOLUMD08A_H

#include "hbridge_interface.h"

class PololuMD08A : public HBridgeInterface
{
private:
	const uint8_t _pin_in1;
	const uint8_t _pin_in2;
	const uint8_t _pin_pwm;

	void setOutputs();

public:
	PololuMD08A(uint8_t pin_in1, uint8_t pin_pwm, Sensor1D *battery_voltage_sensor, uint8_t ID = 0);
	PololuMD08A(uint8_t pin_in1, uint8_t pin_pwm, int16_t battery_voltage, uint8_t ID = 0);
	PololuMD08A(uint8_t pin_in1, uint8_t pin_in2, uint8_t pin_pwm, Sensor1D *battery_voltage_sensor, uint8_t ID = 0);
	PololuMD08A(uint8_t pin_in1, uint8_t pin_in2, uint8_t pin_pwm, int16_t battery_voltage, uint8_t ID = 0);

	bool init();
};

#endif //POLOLUMD08A_H
