
#ifndef __SPI_H__
#define __SPI_H__

#include <zephyr/drivers/spi.h>


class Spi
{
    struct BufferSet { spi_buf buffer; spi_buf_set set; };
public:
    Spi(spi_dt_spec const& spec);

    bool write(uint8_t* tx, uint16_t size) const;
    bool read(uint8_t* rx, uint16_t size) const;
    bool transceive(uint8_t* tx, uint8_t* rx, uint16_t size) const;

    bool isReady() const;

private:
    BufferSet makeBuffer(uint8_t* data, uint16_t size) const;

    spi_dt_spec const _spec;
};

#endif