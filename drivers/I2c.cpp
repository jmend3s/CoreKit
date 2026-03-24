
#include "I2c.h"

I2c::I2c(I2cSpec& spec)
    : _i2c(spec)
{
}

bool I2c::isReady()
{
}

int I2c::write(uint8_t* tx, uint8_t size)
{
}

int I2c::read(uint8_t* rx, uint8_t size)
{
}

int I2c::writeRead(uint8_t* tx, uint8_t txSize, uint8_t* rx, uint8_t rxSize)
{
}
