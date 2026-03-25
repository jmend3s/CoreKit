
#include "Mpu6050.h"


Mpu6050::Mpu6050(II2c& i2c)
    : _i2c(i2c)
{
}

bool Mpu6050::initialize()
{
    uint8_t data[2];

    data[0] = Mpu6050Registers::pwrMgmt1;
    data[1] = 0x00;

    return _i2c.write(data, 2) == 0;
}

bool Mpu6050::readRaw(ImuRawData& data)
{
    uint8_t reg = 0x3B;
    uint8_t buffer[14];

    if (_i2c.writeRead(&reg, 1, buffer, 14) != 0)
        return false;

    data.ax = (buffer[0] << 8) | buffer[1];
    data.ay = (buffer[2] << 8) | buffer[3];
    data.az = (buffer[4] << 8) | buffer[5];

    data.gx = (buffer[8] << 8) | buffer[9];
    data.gy = (buffer[10] << 8) | buffer[11];
    data.gz = (buffer[12] << 8) | buffer[13];

    return true;
}
