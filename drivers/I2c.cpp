
#include "I2c.h"

I2c::I2c(I2cSpec& spec)
    : _i2c(spec)
{
}

bool I2c::isReady()
{
    return _i2c.isReady();
}

int I2c::write(uint8_t* tx, uint8_t size)
{
    return _i2c.write(tx, size);
}

int I2c::read(uint8_t* rx, uint8_t size)
{
    return _i2c.read(rx, size);
}

int I2c::writeRead(uint8_t* tx, uint8_t txSize, uint8_t* rx, uint8_t rxSize)
{
    return _i2c.writeRead(tx, txSize, rx, rxSize);
}
