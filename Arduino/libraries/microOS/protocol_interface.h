#ifndef PROTOCOL_INTERFACE_H
#define PROTOCOL_INTERFACE_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ProtocolInterface
{
public:
    virtual bool decode(uint8_t b) = 0;
    virtual uint16_t encode(void* msg, uint8_t* buffer) = 0;
    
    virtual uint32_t getPacketsReceived() = 0;
    virtual uint32_t getPacketsDropped() = 0;
    virtual void* getMessage() = 0;
};

#endif //PROTOCOL_INTERFACE_H
