
#ifndef __LOG_FORMATTER_H__
#define __LOG_FORMATTER_H__

#include "LogRecord.h"

#include <cstdio>


class LogFormater
{
public:
    static uint32_t format(LogRecord const& record, char* buffer, size_t bufferSize);

private:
    // static bool append(char* buffer, size_t bufferSize, size_t& offset, char const* fmt, ...);
    static bool appendHeader(char* buffer, size_t bufferSize, size_t& offset, LogRecord const& record);
    static bool appendString(char* buffer, size_t bufferSize, size_t& offset, char const* text);
    static char* itoa(int value);
    static char const* levelToString(LogLevel level);
};

#endif
