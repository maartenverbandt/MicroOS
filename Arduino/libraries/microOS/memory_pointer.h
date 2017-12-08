#ifndef MEMORY_POINTER_H
#define MEMORY_POINTER_H

#include <EEPROM.h>

class MemoryPointer {
    private:
        static uint16_t _address;

    public:
        static uint16_t get(){ return _address; }
        static void set(int address){ _address = address; }
        static void increment(int increment){ _address += increment; }
};

#endif // MEMORY_POINTER_H
