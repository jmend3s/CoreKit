
#ifndef __SPI_H__
#define __SPI_H__

#include "ISpi.h"
#include "zephyr/SpiWrapper.h"


using SpiSpec = SpiWrapper::SpecHandle;
class Spi : public ISpi
{
public:
    Spi(SpiSpec& spec);

    Result write(uint8_t const* tx, uint16_t size) override;
    Result read(uint8_t* rx, uint16_t size) override;
    Result transceive(uint8_t const* tx, uint8_t* rx, uint16_t size) override;

private:
    SpiWrapper _spi;
};

#endif