
#ifndef __LOG_LEVELS_H__
#define __LOG_LEVELS_H__

#include <cstdint>



enum class LogLevel : uint8_t
{
    Debug = 0,
    Info,
    Warn,
    Error,
    Fatal
};


#endif
