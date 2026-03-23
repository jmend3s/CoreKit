
#ifndef __I_IMU_H__
#define __I_IMU_H__

#include "ImuTypes.h"


class IImu
{
public:
    virtual bool init() = 0;
    virtual bool readRaw(ImuRawData& data) = 0;
    virtual bool readScaled(ImuScaledData& data) = 0;

    virtual ~IImu() = default;
};


#endif
