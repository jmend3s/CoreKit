
#ifndef __LOGRECORD_H__
#define __LOGRECORD_H__

#include "LogArgument.h"
#include "LogLevels.h"

#include <cstdint>


uint32_t constexpr MAX_LOG_ARGUMENTS = 6;

struct LogRecord
{
    uint32_t timestamp;
    LogLevel level;
    char const* module;
    char const* message;
    uint8_t argumentCount;
    LogArgument arguments[MAX_LOG_ARGUMENTS];
};


#endif
