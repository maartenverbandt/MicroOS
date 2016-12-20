#include <microOS.h>

int counter = 0;
int increment = 0;
int sensor = 0;

int countingTask(void)
{
	counter += increment;
	System.setGPoutInt(0,counter);
	
	return 0;
}

int sensorTask(void)
{
	sensor = analogRead(A0);
	System.setGPoutInt(1,sensor);
	
	return 0;
}

int readIncrement(void)
{
	increment = System.getGPinInt(0);
	System.setGPoutFloat(0,increment);
	
	return 0;
}

void setup()
{
	System.addThread(NORMAL, 20000, &sensorTask, false); //read sensor@50Hz
	System.addThread(BELOWNORMAL, 100000, &readIncrement, false); //read command@10Hz
	System.addThread(LOWEST, 1000000, &countingTask, false); //update counter@1Hz

	System.start(SEQUENTIAL); //
}

void loop()
{
	System.run(RESCHEDULED); //
}

