#include <storage.h>
#include <EEPROM.h>

Storage<float> fstorage;
Storage<uint8_t> ustorage;
Storage<int32_t> istorage;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Starting test...");

    // add offset to memory pointer
    if(MemoryPointer::get() != 0) { Serial.print("Memory pointer: "); Serial.println(MemoryPointer::get()); }
    MemoryPointer::set(16); 
    if(MemoryPointer::get() != 16) { Serial.print("Memory pointer: "); Serial.println(MemoryPointer::get()); }

    // check one parameter
    Parameter<float> *p;
    fstorage.add("float0");
    if (!fstorage.get("float0",p)) {
        Serial.println("Error: parameter float0 not found");
    } else {
        // check address
        if (p->address() != 16) { Serial.print("Error: parameter float0 has wrong address. Expected 16 but is"); Serial.println(p->address()); }

        // check value storage
        p->storeValue(1.7);
        if (p->value() != 1.7) { Serial.print("Error: parameter float0 has wrong value (First). Expected 1.7 but is"); Serial.println(p->value()); }
        
        // check value changing
        p->setValue(-5.2);
        if (p->value() != -5.2) { Serial.print("Error: parameter float0 has wrong value (Second). Expected -5.2 but is"); Serial.println(p->value()); }

        // check loading
        p->loadValue();
        if (p->value() != 1.7) { Serial.print("Error: parameter float0 has wrong value (Third). Expected 1.7 but is"); Serial.println(p->value()); }
    }

    // Add another parameter
    fstorage.add("float1");
    if (!fstorage.get("float1",p)) {
        Serial.println("Error: parameter float1 not found");
    } else {
        // check address
        if (p->address() != 20) { Serial.print("Error: parameter float1 has wrong address. Expected 16+4=20 but is"); Serial.println(p->address()); }
    }
        
    // Add an uint8_t parameter
    Parameter<uint8_t> *pu;
    ustorage.add("uint8_0");
    if (!ustorage.get("uint8_0",pu)) {
        Serial.println("Error: parameter uint8_0 not found");
    } else {
        // check address
        if (pu->address() != 24) { Serial.print("Error: parameter uint8_0 has wrong address. Expected 16+4+4=24 but is"); Serial.println(pu->address()); }
    }

    // Add an int32_t parameter
    Parameter<int32_t> *pi;
    istorage.add("int32_0");
    if (!istorage.get("int32_0",pi)) {
        Serial.println("Error: parameter int32_0 not found");
    } else {
        // check address
        if (pi->address() != 25) { Serial.print("Error: parameter int32_0 has wrong address. Expected 16+4+1+4=25 but is"); Serial.println(pi->address()); }
    }

    // Add an uint8_t parameter
    ustorage.add("uint8_1");
    if (!ustorage.get("uint8_1",pu)) {
        Serial.println("Error: parameter uint8_1 not found");
    } else {
        // check address
        if (pu->address() != 29) { Serial.print("Error: parameter uint8_1 has wrong address. Expected 16+4+4+1+4=29 but is"); Serial.println(pu->address()); }
    }


    // check existance of all parameters
    if (!fstorage.get("float0",p)) { Serial.println("Error: parameter float0 not found"); }
    if (!fstorage.get("float1",p)) { Serial.println("Error: parameter float1 not found"); }
    if (!ustorage.get("uint8_0",pu)) { Serial.println("Error: parameter uint8_0 not found"); }
    if (!ustorage.get("uint8_1",pu)) { Serial.println("Error: parameter uint8_1 not found"); }
    if (!istorage.get("int32_0",pi)) { Serial.println("Error: parameter int32_0 not found"); }
    
    Serial.println("Testing done!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
