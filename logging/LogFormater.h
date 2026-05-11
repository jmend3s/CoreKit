
#ifndef __LOG_FORMATTER_H__
#define __LOG_FORMATTER_H__

#include "LogRecord.h"

#include <cstdint>


class LogFormater
{
public:
    static uint32_t format(LogRecord const& record, char* buffer, uint32_t bufferSize);

private:
    static bool append(char* buffer, uint32_t bufferSize, uint32_t& offset, char const* fmt, ...);
    static char const* levelToString(LogLevel level);
};

#endif
