#include "hal_base.h"

HALBase::HALBase(const uint8_t onboard_led_pin, const uint8_t version) :
	_version(version), _onboard_led_pin(onboard_led_pin), _onboard_led_state(false), _primary_serial(&Serial), _secondary_serial(NULL), _primary_baud(115200), _secondary_baud(115200)
{
	pinMode(_onboard_led_pin, OUTPUT);
	digitalWrite(_onboard_led_pin, _onboard_led_state);
}

bool HALBase::init()
{
	onboardLedToggle();
	
	if(getPrimarySerial()!=NULL){
		getPrimarySerial()->begin(_primary_baud);
	}
	if(getSecondarySerial()!=NULL){
		getSecondarySerial()->begin(_secondary_baud);
	}
	return true;
}

const uint8_t HALBase::version()
{
	return _version;
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

HardwareSerial* HALBase::getSerial()
{
	return getPrimarySerial();
}

HardwareSerial* HALBase::getPrimarySerial()
{
	return _primary_serial;
}

HardwareSerial* HALBase::getSecondarySerial()
{
	return _secondary_serial;
}

void HALBase::setPrimarySerial(HardwareSerial *serial)
{
	_primary_serial = serial;
}

void HALBase::setSecondarySerial(HardwareSerial *serial)
{
	_secondary_serial = serial;
}

void HALBase::setBaud(uint32_t baud)
{
	setPrimaryBaud(baud);
	setSecondaryBaud(baud);
}

void HALBase::setPrimaryBaud(uint32_t baud)
{
	_primary_baud = baud;
}

void HALBase::setSecondaryBaud(uint32_t baud)
{
	_secondary_baud = baud;
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
