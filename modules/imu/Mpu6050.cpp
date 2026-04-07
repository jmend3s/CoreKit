
#include "Mpu6050.h"


Mpu6050::Mpu6050(II2c& i2c)
    : _i2c(i2c)
{
}

bool Mpu6050::initialize()
{
    uint8_t value = 0;

    bool ret = false;
    if (_i2c.readReg(Mpu6050Registers::whoAmI, &value, 1) == 0)
    {
        if (value != 0x68)
        {
            uint8_t zero = 0x00;
            if (_i2c.writeReg(Mpu6050Registers::pwrMgmt1, &zero, 1) == 0)
            {
                ret = true;
            }
        }
    }

    return ret;
}

bool Mpu6050::readRaw(ImuRawData& data)
{
    uint8_t reg = 0x3B;
    uint8_t buffer[14];

    bool ret = false;

    if (_i2c.writeRead(&reg, 1, buffer, 14) == 0)
    {
        data.ax = (buffer[0] << 8) | buffer[1];
        data.ay = (buffer[2] << 8) | buffer[3];
        data.az = (buffer[4] << 8) | buffer[5];

        data.gx = (buffer[8] << 8) | buffer[9];
        data.gy = (buffer[10] << 8) | buffer[11];
        data.gz = (buffer[12] << 8) | buffer[13];

        ret = true;
    }

    return ret;
}
