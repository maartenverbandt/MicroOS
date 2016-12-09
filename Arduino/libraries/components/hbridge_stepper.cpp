/*
  Stepper.cpp - - Stepper library for Wiring/Arduino - Version 0.4
  
  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley  

  Drives a unipolar or bipolar stepper motor using  2 wires or 4 wires

  When wiring multiple stepper motors to a microcontroller,
  you quickly run out of output pins, with each motor requiring 4 connections. 

  By making use of the fact that at any time two of the four motor
  coils are the inverse  of the other two, the number of
  control connections can be reduced from 4 to 2. 

  A slightly modified circuit around a Darlington transistor array or an L293 H-bridge
  connects to only 2 microcontroler pins, inverts the signals received,
  and delivers the 4 (2 plus 2 inverted ones) output signals required
  for driving a stepper motor.

  The sequence of control signals for 4 control wires is as follows:

  Step C0 C1 C2 C3
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1

  The sequence of controls signals for 2 control wires is as follows
  (columns C1 and C2 from above):

  Step C0 C1
     1  0  1
     2  1  1
     3  1  0
     4  0  0

  The circuits can be found at 
 
http://www.arduino.cc/en/Tutorial/Stepper
 
 
 */


#include "hbridge_stepper.h"

/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */

HBridgeStepper::HBridgeStepper(const uint8_t ID, const uint8_t pin_1, const uint8_t pin_2, const uint8_t pin_3, const uint8_t pin_4) :
	Stepper(ID),
	_pin_1(pin_1),
	_pin_2(pin_2),
	_pin_3(pin_3),
	_pin_4(pin_4)
{
	//do nothing 
}

bool HBridgeStepper::init()
{
	// setup the pins on the microcontroller:
	pinMode(_pin_1, OUTPUT);
	pinMode(_pin_2, OUTPUT);
	pinMode(_pin_3, OUTPUT);
	pinMode(_pin_4, OUTPUT);
	
	return true;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative, 
   the motor moves in the reverse direction.
 */
void HBridgeStepper::stepCW(){
	_position++;
	stepToPosition();
}

void HBridgeStepper::stepCCW(){
	_position--;
	stepToPosition();
}


/*{  
  int steps_left = abs(steps_to_move);  // how many steps to take
  
  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) {this->direction = 1;}
  if (steps_to_move < 0) {this->direction = 0;}
    
    
  // decrement the number of steps, moving one step each time:
  while(steps_left > 0) {
  // move only if the appropriate delay has passed:
  if (millis() - this->last_step_time >= this->step_delay) {
      // get the timeStamp of when you stepped:
      this->last_step_time = millis();
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      } 
      else { 
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, 2, or 3:
      stepMotor(this->step_number % 4);
    }
  }
}*/

/*
 * Moves the motor forward or backwards.
 */
void HBridgeStepper::stepToPosition()
{
    switch (_position&(0x00000003)) {
		case 0:    // 1010
		digitalWrite(_pin_1, HIGH);
		digitalWrite(_pin_2, LOW);
		digitalWrite(_pin_3, HIGH);
		digitalWrite(_pin_4, LOW);
		break;
		case 1:    // 0110
		digitalWrite(_pin_1, LOW);
		digitalWrite(_pin_2, HIGH);
		digitalWrite(_pin_3, HIGH);
		digitalWrite(_pin_4, LOW);
		break;
		case 2:    //0101
		digitalWrite(_pin_1, LOW);
		digitalWrite(_pin_2, HIGH);
		digitalWrite(_pin_3, LOW);
		digitalWrite(_pin_4, HIGH);
		break;
		case 3:    //1001
		digitalWrite(_pin_1, HIGH);
		digitalWrite(_pin_2, LOW);
		digitalWrite(_pin_3, LOW);
		digitalWrite(_pin_4, HIGH);
		break;
    }
}
