#ifndef HBRIDGE_INTERFACE
#define HBRIDGE_INTERFACE

#include "component_interface.h"
#include "sensor1D.h"

class HBridgeInterface : public ComponentInterface
{
	protected:
		bool _polarity;		//polarity pin value
		uint8_t _pwm;			//pwm value

		Sensor1D* _battery_voltage_sensor;	//battery voltage sensor

		virtual void setOutputs() = 0;
		void setPolarity(bool polarity);
		void setPWM(uint8_t pwm);

	public:
		HBridgeInterface(Sensor1D *battery_voltage_sensor, uint8_t ID = 0);
		HBridgeInterface(int16_t battery_voltage, uint8_t ID = 0);

		virtual bool init() = 0;
		void setBridgeVoltage(int16_t bridge_voltage);		//set bridge voltage

		Sensor1D *batteryVoltageSensor();
		int16_t getBridgeVoltage();
		bool getPolarity();
		int16_t getPWM();
};

#endif //HBRIDGE_INTERFACE
