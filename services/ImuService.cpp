
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
        _valid = false;
    }
}

void ImuService::update()
{
    if (ImuRawData data{};
        _imu.readRaw(data))
    {
        _last = _scaler.scale(data);
        Printer::print("AX:%.2f AY:%.2f AZ:%.2f | GX:%.2f GY:%.2f GZ:%.2f\n",
            _last.ax, _last.ay, _last.az,
            _last.gx, _last.gy, _last.gz);
        _valid = true;
    }
    else
    {
        _valid = false;
    }
}

uint32_t ImuService::period() const
{
    return 10; // 100 Hz
}

ImuData ImuService::get() const
{
    return _last;
}

bool ImuService::hasValidData() const
{
    return _valid;
}
