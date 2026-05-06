
#include "Mpu6050.h"
#include "Delay.h"


Mpu6050::Mpu6050(II2c& i2c)
    : _i2c(i2c)
{
}

bool Mpu6050::initialize()
{
    uint8_t who = 0;

    bool ret = false;
    if (_i2c.readReg(Mpu6050Registers::whoAmI, &who, 1) == 0)
    {
        if (who == 0x68)
        {
            uint8_t zero = 0x00;
            if (_i2c.writeReg(Mpu6050Registers::pwrMgmt1, &zero, 1) == 0)
            {
                Delay::ms(10);
                ret = true;
            }
        }
    }
    return ret;
}

bool Mpu6050::readRaw(ImuRawData& data)
{
    uint8_t buffer[14];
    bool ret = false;
    if (_i2c.readReg(Mpu6050Registers::accelXoutH, buffer, 14) == 0)
    {
        data.ax = static_cast<int16_t>(static_cast<uint16_t>(buffer[0]) << 8 | buffer[1]);
        data.ay = static_cast<int16_t>(static_cast<uint16_t>(buffer[2]) << 8 | buffer[3]);
        data.az = static_cast<int16_t>(static_cast<uint16_t>(buffer[4]) << 8 | buffer[5]);

        data.gx = static_cast<int16_t>(static_cast<uint16_t>(buffer[8]) << 8 | buffer[9]);
        data.gy = static_cast<int16_t>(static_cast<uint16_t>(buffer[10]) << 8 | buffer[11]);
        data.gz = static_cast<int16_t>(static_cast<uint16_t>(buffer[12]) << 8 | buffer[13]);
        ret = true;
    }

    return ret;
}
