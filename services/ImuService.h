
#ifndef __IMU_SERVICE_H__
#define __IMU_SERVICE_H__

#include "Component.h"

#include "imu/DataScaler.h"
#include "imu/IImu.h"
#include "imu/ImuTypes.h"


class ImuService : public Component
{
public:
    ImuService(IImu& imu);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

    ImuData get() const;
    bool hasValidData() const;

private:
    IImu& _imu;
    ImuData _last{};
    DataScaler _scaler;

    bool _valid = false;
};


#endif
