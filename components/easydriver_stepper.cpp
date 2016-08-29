#include "easydriver_stepper.h"

EasydriverStepper::EasydriverStepper(const uint8_t ID, const uint8_t pin_step, const uint8_t pin_dir) :
	Stepper(ID),
	_pin_step(pin_step),
	_pin_dir(pin_dir)
{
	//do nothing
}

bool EasydriverStepper::init(){
	// setup the pins on the microcontroller:
	pinMode(_pin_step, OUTPUT);
	pinMode(_pin_dir, OUTPUT);
	
	return true;
}

void EasydriverStepper::stepCW(){
	_position++;
	digitalWrite(_pin_dir, HIGH);
	digitalWrite(_pin_step, HIGH);
	digitalWrite(_pin_step, LOW);
}

void EasydriverStepper::stepCCW(){
	_position--;
	digitalWrite(_pin_dir, LOW);
	digitalWrite(_pin_step, HIGH);
	digitalWrite(_pin_step, LOW);
}
