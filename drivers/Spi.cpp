
#include "Spi.h"

Spi::Spi(spi_dt_spec const& spec)
    : _spec(spec)
{
}

bool Spi::write(uint8_t* tx, uint16_t const size) const
{
    return transceive(tx, nullptr, size);
}

bool Spi::read(uint8_t* rx, uint16_t const size) const
{
    return transceive(rx, nullptr, size);
}

bool Spi::transceive(uint8_t* tx, uint8_t* rx, uint16_t const size) const
{
    bool success = false;

    if (isReady() && size > 0)
    {
        auto [txBuffer, txSet] = tx ? makeBuffer(tx, size) : BufferSet{};
        auto [rxBuffer, rxSet] = rx ? makeBuffer(rx, size) : BufferSet{};

        int const ret = spi_transceive_dt(
            &_spec,
            tx ? &txSet : nullptr,
            rx ? &rxSet : nullptr
        );

        success = ret == 0;
    }

    return success;
}

bool Spi::isReady() const
{
    return spi_is_ready_dt(&_spec);
}

Spi::BufferSet Spi::makeBuffer(uint8_t* data, uint16_t const size) const
{
    BufferSet bufferSet { { data, size }, { &bufferSet.buffer, 1 } };
    return bufferSet;
}
