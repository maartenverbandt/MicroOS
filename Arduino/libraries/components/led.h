#ifndef LED_H
#define LED_H

#include "component_interface.h"

//!  LED Class 
/*!
  Class incorporating the control of on-board leds.
*/
class LED : public ComponentInterface
{
private:    
    /*LED attributes*/
    uint8_t _pin;				/*!< Pin to which the led is connected. */ 
    bool _on;              		/*!< Led state: true=on, false=off. (master control) */

    unsigned long _wake_up;
    uint16_t _on_time;
    uint16_t _off_time;
    
public:
    //! LED constructor
    LED(uint8_t pin, uint8_t ID = 0);
    
    ///////////////
    /// FUNCTIONAL
    bool init();
    void update();

    ///////////////
    /// SET-METHODS
    void ledOn();
    void ledOff();
    uint8_t setSchedule(uint8_t duty_cycle, uint16_t period);
    
    ///////////////
    /// GET-METHODS
    bool getOn();
	uint16_t getOntime();
};

//extern LED teensyLED;
#endif //AP_ESTIMATOR_H
