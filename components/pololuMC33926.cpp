#include "pololuMC33926.h"

PololuMC33926::PololuMC33926(uint8_t in1, uint8_t in2, Sensor1D *battery_voltage_sensor, uint8_t ID) :
	HBridgeInterface(battery_voltage_sensor, ID), _in1(in1), _in2(in2), _D1(0xFF), _D2(0xFF)
{
	//do nothing
}

PololuMC33926::PololuMC33926(uint8_t in1, uint8_t in2, int16_t battery_voltage, uint8_t ID) :
	HBridgeInterface(battery_voltage, ID), _in1(in1), _in2(in2), _D1(0xFF), _D2(0xFF)
{

	//do nothing
}

PololuMC33926::PololuMC33926(uint8_t in1, uint8_t in2, uint8_t D1, uint8_t D2, Sensor1D *battery_voltage_sensor, uint8_t ID) :
	HBridgeInterface(battery_voltage_sensor, ID), _in1(in1), _in2(in2), _D1(D1), _D2(D2)
{
	//do nothing
}

PololuMC33926::PololuMC33926(uint8_t in1, uint8_t in2, uint8_t D1, uint8_t D2, int16_t battery_voltage, uint8_t ID) :
	HBridgeInterface(battery_voltage, ID), _in1(in1), _in2(in2), _D1(D1), _D2(D2)
{
	//do nothing
}

bool PololuMC33926::init()
{
	pinMode(_in1, OUTPUT);
	pinMode(_in2, OUTPUT);
	if((_D1&_D2)==0xFF){
#ifdef CORE_TEENSY
		//increase pwm frequency to 20kHz
		analogWriteFrequency(_in1, 20000); //only works when compiling for teensy... TODO: set teensy flag
		analogWriteFrequency(_in2, 20000); //only works when compiling for teensy... TODO: set teensy flag
#endif
	}

	if(_D1!=0xFF){
		pinMode(_D1, OUTPUT);
#ifdef CORE_TEENSY
		analogWriteFrequency(_D1, 20000);
#endif
	}
	else if(_D2!=0xFF){
		pinMode(_D2, OUTPUT);
#ifdef CORE_TEENSY
		analogWriteFrequency(_D2, 20000);
#endif
	}

#ifdef CORE_TEENSY
	analogWriteResolution(8);
#endif

	return _battery_voltage_sensor->init();
}

void PololuMC33926::setOutputs()
{
	if((_D1&_D2)==0xFF){
		if(_polarity){
			analogWrite(_in1, _pwm);
			analogWrite(_in2, 0);
		} else {
			analogWrite(_in1, 0);
			analogWrite(_in2, _pwm);
		}
	} else {
		digitalWrite(_in1, _polarity);
		digitalWrite(_in2, !_polarity);
		if(_D1!=0xFF){
			analogWrite(_D1, _pwm);
		} else {
			analogWrite(_D2, _pwm);
		}
	}
}
