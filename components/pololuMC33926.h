#ifndef POLOLUMC33926_H
#define POLOLUMC33926_H

#include "hbridge_interface.h"

typedef enum {
	POLOLUMC33926_PWM_IN,
	POLOLUMC33926_PWM_D
} pololuMC33926_pwm_mode_t;

class PololuMC33926 : public HBridgeInterface
{
	private:
		const uint8_t _in1;
		const uint8_t _in2;
		const uint8_t _D1;
		const uint8_t _D2;

		void setOutputs();

	public:
		PololuMC33926(uint8_t in1, uint8_t in2, Sensor1D *battery_voltage_sensor, uint8_t ID = 0);
		PololuMC33926(uint8_t in1, uint8_t in2, int16_t battery_voltage, uint8_t ID = 0);
		PololuMC33926(uint8_t in1, uint8_t in2, uint8_t D1, uint8_t D2, Sensor1D *battery_voltage_sensor, uint8_t ID = 0);
		PololuMC33926(uint8_t in1, uint8_t in2, uint8_t D1, uint8_t D2, int16_t battery_voltage, uint8_t ID = 0);

		bool init();
};

#endif //POLOLUMC33926
