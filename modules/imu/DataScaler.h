
#ifndef __DATA_SCALER_H__
#define __DATA_SCALER_H__

#include "ImuTypes.h"


class DataScaler
{
public:
    ImuData scale(ImuRawData const& raw);

private:
    float const _accelScale = 16384.0f;
    float const _gyroScale  = 131.0f;

    float const _gravity = 9.80665f;
    float const _degreesToRadians = 3.14159265359f / 180.0f;
};


#endif
