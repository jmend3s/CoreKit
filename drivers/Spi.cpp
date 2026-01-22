
#include "Spi.h"

Spi::Spi(SpiSpec& spec)
    : _hal(spec)
{
}

bool Spi::write(uint8_t* tx, uint16_t const size)
{
    return transceive(tx, nullptr, size);
}

bool Spi::read(uint8_t* rx, uint16_t const size)
{
    return transceive(nullptr, rx, size);
}

bool Spi::transceive(uint8_t* tx, uint8_t* rx, uint16_t const size)
{
    bool success = false;

    if (_hal.isReady())
    {
        int const ret = _hal.transceive(tx, rx, size);
        success = ret == 0;
    }

    return success;
}
