
#ifndef __IMU_TYPES_H__
#define __IMU_TYPES_H__

#include <cstdint>


struct ImuRawData
{
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;

    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
};

struct ImuScaledData
{
    float accel_x; // m/s^2
    float accel_y;
    float accel_z;

    float gyro_x;  // rad/s
    float gyro_y;
    float gyro_z;
};

struct Orientation
{
    float roll;
    float pitch;
    float yaw;
};


#endif