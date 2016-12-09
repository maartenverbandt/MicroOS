#ifndef HAL_BASE_H
#define HAL_BASE_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class HALBase
{
private:
	Stream*	_primary_serial;
	Stream*	_secondary_serial;

	const uint8_t 	_onboard_led_pin;
	bool 			_onboard_led_state;
	
	
public:	
	HALBase(const uint8_t onboard_led_pin = 13, const uint8_t version = 0);
	
	virtual bool init();
	
	const uint8_t onboardLedPin();
	void onboardLedToggle();
	
	Stream* getSerial(int index = 0);
	Stream* getPrimarySerial();
	Stream* getSecondarySerial();
	void setPrimarySerial(Stream *serial);
	void setSecondarySerial(Stream *serial);
	
	uint8_t setAnalogReadResolution(const uint8_t resolution);
};

#endif //HAL_BASE_H
