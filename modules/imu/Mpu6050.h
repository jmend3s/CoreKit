
#ifndef __MPU6050_H__
#define __MPU6050_H__

#include "IImu.h"
#include "ImuTypes.h"

#include "II2c.h"


class Mpu6050 : public IImu
{
public:
    Mpu6050(II2c& i2c);

    bool initialize() override;
    bool readRaw(ImuRawData& data) override;

private:
    II2c& _i2c;
};

namespace Mpu6050Registers
{
    constexpr uint8_t whoAmI = 0x75;
    constexpr uint8_t pwrMgmt1 = 0x6B;
    constexpr uint8_t accelXoutH = 0x3B;
}


#endif
