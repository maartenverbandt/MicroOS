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
	const uint8_t 	_version;	
	const uint8_t 	_onboard_led_pin;
	bool 			_onboard_led_state;
	
	HardwareSerial*	_primary_serial;
	HardwareSerial*	_secondary_serial;
	uint32_t		_primary_baud;
	uint32_t		_secondary_baud;
	
public:	
	HALBase(const uint8_t onboard_led_pin = 13, const uint8_t version = 0);
	
	virtual bool init();
	
	const uint8_t version();
	const uint8_t onboardLedPin();
	void onboardLedToggle();
	
	HardwareSerial* getSerial();
	HardwareSerial* getPrimarySerial();
	HardwareSerial* getSecondarySerial();
	void setPrimarySerial(HardwareSerial *serial);
	void setSecondarySerial(HardwareSerial *serial);
	void setBaud(uint32_t baud);
	void setPrimaryBaud(uint32_t baud);
	void setSecondaryBaud(uint32_t baud);
	
	uint8_t setAnalogReadResolution(const uint8_t resolution);
};

#endif //HAL_BASE_H
