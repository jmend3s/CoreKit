
#ifndef __MPU_6050_H__
#define __MPU_6050_H__

#include "IImu.h"
#include "ImuTypes.h"

#include "ISpi.h"

class Mpu6050 : public IImu
{
public:
    Mpu6050(ISpi& spi);

    bool init() override;
    bool readRaw(ImuRawData& data) override;
    bool readScaled(ImuScaledData& data) override;

private:
    void applyScaling(const ImuRawData& raw, ImuScaledData& scaled);

    ISpi& _spi;

    float _gyroBiasX;
    float _gyroBiasY;
    float _gyroBiasZ;

    float _accelOffsetX;
    float _accelOffsetY;
    float _accelOffsetZ;
};

#endif