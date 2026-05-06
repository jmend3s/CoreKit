
#ifndef __IMU_TYPES_H__
#define __IMU_TYPES_H__

#include <cstdint>


struct ImuRawData
{
    int16_t ax;
    int16_t ay;
    int16_t az;

    int16_t gx;
    int16_t gy;
    int16_t gz;
};

struct ImuData
{
    float ax;
    float ay;
    float az;

    float gx;
    float gy;
    float gz;
};


#endif
