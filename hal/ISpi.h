
#ifndef __I_SPI_H__
#define __I_SPI_H__

#include "Result.h"

#include  <cstdint>


class ISpi
{
public:
    virtual Result write(uint8_t const* tx, uint16_t size) = 0;
    virtual Result read(uint8_t* rx, uint16_t size) = 0;
    virtual Result transceive(uint8_t const* tx, uint8_t* rx, uint16_t size) = 0;
    virtual ~ISpi() = default;
};


#endif
