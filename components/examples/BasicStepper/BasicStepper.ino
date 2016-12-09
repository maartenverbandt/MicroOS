#include "easydriver_stepper.h"
#include "math.h"

unsigned long scheduled_time; 
EasydriverStepper stepper(0, 1, 2);
int position;
int old_position;
int diff;

void setup()
{
	Serial.begin(115200);
	scheduled_time = micros();
	old_position = 0;
}

void loop()
{
	if(micros() > (scheduled_time + 2000)){
		scheduled_time += 2000;
		Serial.println(micros());
		stepper.setSpeed(1.0f*sin(2*M_PI*5.0f));
		position = stepper.update(0.001f);
		diff = old_position - position;
		//if((diff>1) || (diff<-1)){
			Serial.println(diff);
		//}		
		old_position = position;
	}
}
