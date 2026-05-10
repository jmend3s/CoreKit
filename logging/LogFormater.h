
#ifndef __LOG_FORMATER_H__
#define __LOG_FORMATER_H__

#include "LogRecord.h"

#include <cstdint>


class LogFormater
{
public:
    static uint32_t format(LogRecord const& record, char* buffer, uint32_t bufferSize);

private:
    static char const* levelToString(LogLevel level);
};

#endif
