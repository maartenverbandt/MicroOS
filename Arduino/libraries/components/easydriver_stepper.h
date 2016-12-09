#ifndef EASYDRIVER_STEPPER_H
#define EASYDRIVER_STEPPER_H

#include "stepper.h"

class EasydriverStepper: public Stepper
{
private:    
    const uint8_t _pin_step;
    const uint8_t _pin_dir;

public:
    EasydriverStepper(const uint8_t ID, const uint8_t pin_step, const uint8_t pin_dir);

	bool init();
    void stepCW();
    void stepCCW();
};

#endif //EASYDRIVER_STEPPER_H
