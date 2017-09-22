#include <microOS.h>

int loopTask(void)
{
	for(int k = 0; k<8; k++)
	  System.setGPoutFloat(k,System.getGPinFloat(k));
	
	for(int k = 0; k<4; k++)
	  System.setGPoutInt(k,System.getGPinInt(k));

	return 0;
}

void setup()
{
	System.addThread(NORMAL, 20000, &loopTask, false); //loop @50Hz
	
	System.start(SEQUENTIAL); //
}

void loop()
{
	System.run(RESCHEDULED); //
}

