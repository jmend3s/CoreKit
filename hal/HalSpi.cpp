
#include "HalSpi.h"

#include <zephyr/drivers/spi.h>


static spi_dt_spec const* toDt(HalSpi::SpecHandle& spec)
{
    return reinterpret_cast<spi_dt_spec const*>(spec.spec());
}

HalSpi::HalSpi(SpecHandle& spec)
    : _spec(spec)
{
}

bool HalSpi::isReady()
{
    return spi_is_ready_dt(toDt(_spec));
}

int HalSpi::transceive(uint8_t* tx, uint8_t* rx, uint16_t const size)
{
    spi_buf txBuf {};
    spi_buf_set txSet {};
    if (tx)
    {
        txBuf = { tx, size };
        txSet = { &txBuf, 1 };
    }

    spi_buf rxBuf {};
    spi_buf_set rxSet {};
    if (rx)
    {
        rxBuf = { rx, size };
        rxSet = { &rxBuf, 1 };
    }

    return spi_transceive_dt(
        toDt(_spec),
        tx ? &txSet : nullptr,
        rx ? &rxSet : nullptr
    );
}
