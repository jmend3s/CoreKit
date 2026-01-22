
#ifndef __SPI_H__
#define __SPI_H__

#include "HalSpi.h"


using SpiSpec = HalSpi::Spec;
class Spi
{
public:
    Spi(SpiSpec& spec);

    bool write(uint8_t* tx, uint16_t size);
    bool read(uint8_t* rx, uint16_t size);
    bool transceive(uint8_t* tx, uint8_t* rx, uint16_t size);

private:
    HalSpi _hal;
};

#endif