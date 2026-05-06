
#include "DataScaler.h"


ImuData DataScaler::scale(ImuRawData const& raw)
{
    ImuData data{};
    data.ax = (static_cast<float>(raw.ax) / _accelScale) * _gravity;
    data.ay = (static_cast<float>(raw.ay) / _accelScale) * _gravity;
    data.az = (static_cast<float>(raw.az) / _accelScale) * _gravity;

    data.gx = (static_cast<float>(raw.gx) / _gyroScale) * _degreesToRadians;
    data.gy = (static_cast<float>(raw.gy) / _gyroScale) * _degreesToRadians;
    data.gz = (static_cast<float>(raw.gz) / _gyroScale) * _degreesToRadians;

    return data;
}
