
#ifndef __I_SPI_H__
#define __I_SPI_H__

#include  <cstdint>


class ISpi
{
public:
    virtual bool write(uint8_t* tx, uint16_t size) = 0;
    virtual bool read(uint8_t* rx, uint16_t size) = 0;
    virtual bool transceive(uint8_t* tx, uint8_t* rx, uint16_t size) = 0;
    virtual ~ISpi() = default;
};


#endif
