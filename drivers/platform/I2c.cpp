
#include "I2c.h"


I2c::I2c(I2cSpec& spec)
    : _i2c(spec)
{
}

bool I2c::isReady()
{
    return _i2c.isReady();
}

int I2c::write(const uint8_t* tx, uint16_t size)
{
    return _i2c.write(const_cast<uint8_t*>(tx), size);
}

int I2c::read(uint8_t* rx, uint16_t size)
{
    return _i2c.read(rx, size);
}

int I2c::writeRead(const uint8_t* tx, uint16_t txSize, uint8_t* rx, uint16_t rxSize)
{
    return _i2c.writeRead(const_cast<uint8_t*>(tx), txSize, rx, rxSize);
}

int I2c::writeReg(uint8_t reg, const uint8_t* data, uint16_t size)
{
    int ret = -1;
    if (uint8_t buffer[32]; size + 1 < sizeof(buffer))
    {
        buffer[0] = reg;
        for (uint16_t i = 0; i < size; i++)
        {
            buffer[i + 1] = data[i];
        }
        ret = _i2c.write(buffer, size + 1);
    }

    return ret;
}

int I2c::readReg(uint8_t reg, uint8_t* data, uint16_t size)
{
    return _i2c.writeRead(&reg, 1, data, size);
}
