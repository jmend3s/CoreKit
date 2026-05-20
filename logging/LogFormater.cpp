
#include "LogFormater.h"
#include "PrinterK.h"

#include <zephyr/sys/printk.h>

#include <cstdarg>
#include <cstdint>


uint32_t LogFormater::format(LogRecord const& record, char* buffer, size_t bufferSize)
{
    size_t offset = 0;
    appendHeader(buffer, bufferSize, offset, record);
    appendString(buffer, bufferSize, offset, record.message);
    for (uint32_t i = 0; i < record.argumentCount; i++)
    {
        PrinterK::print("end\n");
        appendString(buffer, bufferSize, offset, " ");

        LogArgument const& argument = record.arguments[i];
        switch (argument.type)
        {
            // case LogArgumentType::Float:
            //     appendString(buffer, bufferSize, offset, itoa(argument.floatValue));
            //     break;
            case LogArgumentType::Int32:
                appendString(buffer, bufferSize, offset, itoa(argument.intValue));
                break;
            // case LogArgumentType::UInt32:
            //     appendString(buffer, bufferSize, offset, "%u", itoa(argument.uintValue));
            //     break;
            case LogArgumentType::String:
                appendString(buffer, bufferSize, offset, argument.stringValue);
                break;
            // case LogArgumentType::Pointer:
            //     appendString(buffer, bufferSize, offset, "%p", argument.pointerValue);
            //     break;
        }
    }
    // PrinterK::print("end");

    appendString(buffer, bufferSize, offset, "\n");

    if (offset < bufferSize)
    {
        buffer[offset] = '\0';
    }
    else
    {
        buffer[bufferSize - 1] = '\0';
    }

    return offset;
}

bool LogFormater::appendHeader(char* buffer, size_t bufferSize, size_t& offset, LogRecord const& record)
{
    buffer[offset++] = '[';
    appendString(buffer, bufferSize, offset, levelToString(record.level));
    buffer[offset++] = ']';
    buffer[offset++] = '[';
    appendString(buffer, bufferSize, offset, record.module);
    buffer[offset++] = ']';
    buffer[offset++] = ' ';

    return true;
}

bool LogFormater::appendString(char* buffer, size_t const bufferSize, size_t& offset, char const* text)
{
    while (*text != '\0')
    {
        if (offset >= bufferSize - 1)
        {
            return false;
        }

        buffer[offset++] = *text++;
    }

    return true;
}

char* LogFormater::itoa(int value)
{
    static char buffer[12];
    char *ptr = buffer;
    unsigned int uvalue = value;

    if (value == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }

    if (value < 0) {
        *ptr++ = '-';
        uvalue = -((unsigned int)value);
    }

    unsigned int temp = uvalue;
    while (temp > 0) { ptr++; temp /= 10; }
    *ptr = '\0';

    while (uvalue > 0) {
        *--ptr = '0' + (uvalue % 10);
        uvalue /= 10;
    }

    return buffer;
}

// bool LogFormater::append(char* buffer, size_t bufferSize, size_t& offset, char const* fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);
//     int written = vsnprintk(buffer + offset, bufferSize - offset, fmt, args);
//     va_end(args);
//
//     offset += static_cast<size_t>(written);
//
//     return true;
// }

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
