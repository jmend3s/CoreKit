
#ifndef __SPI_H__
#define __SPI_H__

#include "ISpi.h"
#include "SpiWrapper.h"


using SpiSpec = SpiWrapper::SpecHandle;
class Spi : public ISpi
{
public:
    Spi(SpiSpec& spec);

    bool write(uint8_t* tx, uint16_t size);
    bool read(uint8_t* rx, uint16_t size);
    bool transceive(uint8_t* tx, uint8_t* rx, uint16_t size);

private:
    SpiWrapper _spi;
};

#endif