
#include "I2cWrapper.h"

#include <zephyr/drivers/i2c.h>


static const i2c_dt_spec* toDt(I2cWrapper::SpecHandle& spec)
{
    return reinterpret_cast<const i2c_dt_spec*>(spec.spec());
}

I2cWrapper::I2cWrapper(SpecHandle& spec)
    : _spec(spec)
{
}

bool I2cWrapper::isReady()
{
    return i2c_is_ready_dt(toDt(_spec));
}

int I2cWrapper::write(uint8_t* tx, uint16_t size)
{
    return i2c_write_dt(toDt(_spec), tx, size);
}

int I2cWrapper::read(uint8_t* rx, uint16_t size)
{
    return i2c_read_dt(toDt(_spec), rx, size);
}

int I2cWrapper::writeRead(uint8_t* tx, uint16_t txSize, uint8_t* rx, uint16_t rxSize)
{
    return i2c_write_read_dt(toDt(_spec), tx, txSize, rx, rxSize);
}
