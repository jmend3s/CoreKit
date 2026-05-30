
#ifndef __PACKET_H__
#define __PACKET_H__

#include <cstdint>


struct Packet
{
    uint8_t* data;
    uint16_t length;
};


#endif
