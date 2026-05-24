
#ifndef __LOG_FORMATTER_H__
#define __LOG_FORMATTER_H__

#include "LogRecord.h"

#include <cstdio>


class LogFormater
{
public:
    static uint32_t format(LogRecord const& record, char* buffer, size_t bufferSize);

private:
    static bool appendHeader(char* buffer, size_t bufferSize, size_t& offset, LogRecord const& record);
    static bool appendString(char* buffer, size_t bufferSize, size_t& offset, char const* text);
    static bool appendInt(char* buffer, size_t bufferSize, size_t& offset, int32_t value);
    static bool appendUInt(char* buffer, size_t bufferSize, size_t& offset, uint32_t value);
    static bool appendFloat(char* buffer, size_t bufferSize, size_t& offset, float value, uint32_t precision = 3);
    static bool appendPointer(char* buffer, size_t bufferSize, size_t& offset, void const* pointer);
    static bool appendHexadecimal(char* buffer, size_t bufferSize, size_t& offset, uint32_t value, bool prefix = true);
    static bool appendBinary(char* buffer, size_t bufferSize, size_t& offset, uint32_t value);
    static bool appendTimestamp(char* buffer, size_t bufferSize, size_t& offset, uint32_t timestamp);
    static char const* levelToString(LogLevel level);
};

#endif
