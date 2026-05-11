
#include "LogFormater.h"

#include <cstdarg>
#include <cstdio>


uint32_t LogFormater::format(LogRecord const& record, char* buffer, uint32_t bufferSize)
{
    uint32_t offset = 0;
    append(buffer, bufferSize, offset, "TEST");

    // append(buffer, bufferSize, offset, "[%s][%s] ", levelToString(record.level), record.module);
    // append(buffer, bufferSize, offset, "%s", record.message);

    // for (uint32_t i = 0; i < record.argumentCount; ++i)
    // {
    //     append(buffer, bufferSize, offset, " ");
    //
    //     LogArgument const& argument = record.arguments[i];
    //     switch (argument.type)
    //     {
    //         case LogArgumentType::Float:
    //             append(buffer, bufferSize, offset, "%f", argument.floatValue);
    //             break;
    //         case LogArgumentType::Int32:
    //             append(buffer, bufferSize, offset, "%d", argument.intValue);
    //             break;
    //         case LogArgumentType::UInt32:
    //             append(buffer, bufferSize, offset, "%u", argument.uintValue);
    //             break;
    //         case LogArgumentType::String:
    //             append(buffer, bufferSize, offset, "%s", argument.stringValue);
    //             break;
    //         case LogArgumentType::Pointer:
    //             append(buffer, bufferSize, offset, "%p", argument.pointerValue);
    //             break;
    //     }
    // }
    append(buffer, bufferSize, offset, "\n");

    return offset;
}

bool LogFormater::append(char* buffer, uint32_t bufferSize, uint32_t& offset, char const* fmt, ...)
{
    if (offset >= bufferSize)
        return false;

    va_list args;
    va_start(args, fmt);
    int written;
    written = vsnprintf(buffer + offset, bufferSize - offset, fmt, args);

    va_end(args);

    if (written < 0)
        return false;

    offset += static_cast<uint32_t>(written);

    if (offset >= bufferSize)
        offset = bufferSize - 1;

    return true;
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
