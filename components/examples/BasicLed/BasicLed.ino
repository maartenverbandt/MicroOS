#include <led.h>

#define LED_PIN	13
#define LED_ID	10

static LED led = LED(LED_PIN, LED_ID); 

void setup()
{
	led.setSchedule(80, 1000); //set 80% duty cycle with period of 1s
}

void loop()
{
	led.update();
}
