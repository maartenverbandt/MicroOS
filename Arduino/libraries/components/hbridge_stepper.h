/*
  Stepper.h - - Stepper library for Wiring/Arduino - Version 0.4
  
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

// ensure this library description is only included once
#ifndef HBRIDGE_STEPPER_H
#define HBRIDGE_STEPPER_H

#include "stepper.h"

// library interface description
class HBridgeStepper: public Stepper
{
private:    
    // motor pin numbers:
    const uint8_t _pin_1;
    const uint8_t _pin_2;
    const uint8_t _pin_3;
    const uint8_t _pin_4;
    
    void stepToPosition();

public:
    HBridgeStepper(const uint8_t ID, const uint8_t pin_1, const uint8_t pin_2, const uint8_t pin_3, const uint8_t pin_4);

	bool init();
    void stepCW();
    void stepCCW();
};

#endif //HBRIDGE_STEPPER_H

