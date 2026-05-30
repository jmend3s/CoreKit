
#ifndef __ERROR_H__
#define __ERROR_H__

#include <cstdint>


enum class Error : uint8_t
{
    None = 0,

    InvalidArgument,
    Timeout,
    IoError,
    SpiError,
    GpioError,

    DeviceNotReady,
    DeviceNotFound,
    BufferTooSmall
};


#endif
