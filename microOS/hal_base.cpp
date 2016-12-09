#include "hal_base.h"

HALBase::HALBase(const uint8_t onboard_led_pin, const uint8_t version) :
	_onboard_led_pin(onboard_led_pin), _onboard_led_state(false), _primary_serial(&Serial), _secondary_serial(NULL)
{
	pinMode(_onboard_led_pin, OUTPUT);
	digitalWrite(_onboard_led_pin, _onboard_led_state);
}

bool HALBase::init()
{
	// begin primary serial
	Serial.begin(115200);

	// Toggle led
	onboardLedToggle();
	
	return true;
}

const uint8_t HALBase::onboardLedPin()
{
	return _onboard_led_pin;
}

void HALBase::onboardLedToggle()
{
	_onboard_led_state = !_onboard_led_state;
	digitalWrite(_onboard_led_pin, _onboard_led_state);
}	

Stream* HALBase::getSerial(int index)
{
	switch(index){
	case 0:
		return _primary_serial;
	case 1:
		return _secondary_serial;
	}
	return NULL;
}

Stream* HALBase::getPrimarySerial()
{
	return _primary_serial;
}

Stream* HALBase::getSecondarySerial()
{
	return _secondary_serial;
}

void HALBase::setPrimarySerial(Stream *serial)
{
	_primary_serial = serial;
}

void HALBase::setSecondarySerial(Stream *serial)
{
	_secondary_serial = serial;
}

uint8_t HALBase::setAnalogReadResolution(const uint8_t resolution)
{
	#ifdef __arm__
		analogReadResolution(resolution);
		return resolution;
	#else
		return 10;
	#endif
}
