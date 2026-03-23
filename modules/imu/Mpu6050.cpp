
#include "Mpu6050.h"


Mpu6050::Mpu6050(ISpi& spi)
    : _spi(spi)
    , _gyroBiasX(0)
    , _gyroBiasY(0)
    , _gyroBiasZ(0)
    , _accelOffsetX(0)
    , _accelOffsetY(0)
    , _accelOffsetZ(0)
{
}

bool Mpu6050::init()
{
}

bool Mpu6050::readRaw(ImuRawData& data)
{
}

bool Mpu6050::readScaled(ImuScaledData& data)
{
}

void Mpu6050::applyScaling(const ImuRawData& raw, ImuScaledData& scaled)
{
}
