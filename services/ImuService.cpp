
#include "ImuService.h"

ImuService::ImuService(IImu& imu)
    : _imu(imu)
{
}

void ImuService::initialize()
{
    _imu.initialize();
}

void ImuService::update()
{

}

uint32_t ImuService::period() const
{
}
