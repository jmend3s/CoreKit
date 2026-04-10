
#include "ImuService.h"

#include "Printer.h"

ImuService::ImuService(IImu& imu)
    : _imu(imu)
{
}

void ImuService::initialize()
{
    if (!_imu.initialize())
    {
        Printer::print("IMU initialization failed\n");
    }
}

void ImuService::update()
{
    if (ImuRawData data;
        _imu.readRaw(data))
    {
        _last = data;
        Printer::print("AX:%d AY:%d AZ:%d | GX:%d GY:%d GZ:%d\n",
            data.ax, data.ay, data.az,
            data.gx, data.gy, data.gz);
    }
    else
    {
        Printer::print("IMU read? failed\n");
    }
}

uint32_t ImuService::period() const
{
    return 10; // 100 Hz
}
