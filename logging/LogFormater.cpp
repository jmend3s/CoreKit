
#include "LogFormater.h"

#include <cstdio>


uint32_t LogFormater::format(LogRecord const& record, char* buffer, uint32_t bufferSize)
{
    uint32_t offset = 0;
    offset += snprintf(buffer + offset, bufferSize - offset, "[%s][%s] ", levelToString(record.level), record.module);
    offset += snprintf(buffer + offset, bufferSize - offset, "%s", record.message);

    for (uint32_t i = 0; i < record.argumentCount; ++i)
    {
        offset += snprintf(buffer + offset, bufferSize - offset, " ");

        LogArgument const& argument = record.arguments[i];
        switch (argument.type)
        {
        case LogArgumentType::Float:
            offset += snprintf(buffer + offset, bufferSize - offset, "%f", argument.floatValue);
            break;
        case LogArgumentType::Int32:
            offset += snprintf(buffer + offset, bufferSize - offset, "%d", argument.intValue);
            break;
        case LogArgumentType::UInt32:
            offset += snprintf(buffer + offset, bufferSize - offset, "%u", argument.uintValue);
            break;
        case LogArgumentType::String:
            offset += snprintf(buffer + offset, bufferSize - offset, "%s", argument.stringValue);
            break;
        case LogArgumentType::Pointer:
            offset += snprintf(buffer + offset, bufferSize - offset, "%p", argument.pointerValue);
            break;
        }
    }
    offset += snprintf(buffer + offset, bufferSize - offset, "\n");

    return offset;
}

char const* LogFormater::levelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Warn:
            return "WARN";
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Fatal:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}
