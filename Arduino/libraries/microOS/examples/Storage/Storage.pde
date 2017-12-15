#include <EEPROM.h>
#include <microOS.h>

void setup()
{
    MemoryPointer::set(16); 
    Parami *p1 = System.intStorage()->add("var1i");
    Parami *p2 = System.intStorage()->add("var2i");
    Parami *p3 = System.intStorage()->add("var5i");
    Paramf *p4 = System.floatStorage()->add("var3f");
    Paramf *p5 = System.floatStorage()->add("var4f");

    System.setGPoutFloat(0,p1->address());
    System.setGPoutFloat(1,p2->address());
    System.setGPoutFloat(2,p3->address());
    System.setGPoutFloat(3,p4->address());
    System.setGPoutFloat(4,p5->address());

    //System.intStorage()->setValue("var2i",2);

	
	System.start(SEQUENTIAL); //
}

void loop()
{
	System.run(RESCHEDULED); //
}


