
#ifndef __IMU_SERVICE_H__
#define __IMU_SERVICE_H__

#include "Component.h"
#include "imu/IImu.h"


class ImuService : public Component
{
public:
    ImuService(IImu& imu);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

private:
    IImu& _imu;
};


#endif
