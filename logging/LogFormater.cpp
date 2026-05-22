
#include "LogFormater.h"


uint32_t LogFormater::format(LogRecord const& record, char* buffer, size_t bufferSize)
{
    size_t offset = 0;
    appendHeader(buffer, bufferSize, offset, record);
    appendString(buffer, bufferSize, offset, record.message);
    for (uint32_t i = 0; i < record.argumentCount; i++)
    {
        appendString(buffer, bufferSize, offset, " ");

        LogArgument const& argument = record.arguments[i];
        switch (argument.type)
        {
            case LogArgumentType::Float:
                appendFloat(buffer, bufferSize, offset, argument.floatValue);
                break;
            case LogArgumentType::Int32:
                appendInt(buffer, bufferSize, offset, argument.intValue);
                break;
            case LogArgumentType::UInt32:
                appendUInt(buffer, bufferSize, offset, argument.uintValue);
                break;
            case LogArgumentType::String:
                appendString(buffer, bufferSize, offset, argument.stringValue);
                break;
            case LogArgumentType::Pointer:
                appendPointer(buffer, bufferSize, offset, argument.pointerValue);
                break;
        }
    }
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
    bool ret = false;
    if (text != nullptr)
    {
        while (*text != '\0')
        {
            if (offset >= bufferSize - 1)
            {
                break;
            }

            buffer[offset++] = *text++;
        }

        if (offset < bufferSize - 1)
        {
            ret = true;
        }
    }

    return ret;
}

bool LogFormater::appendInt(char* buffer, size_t bufferSize, size_t& offset, int32_t value)
{
    bool ret = false;
    if (offset < bufferSize - 1)
    {
        if (value == 0)
        {
            buffer[offset++] = '0';
            ret = true;
        }
        else if (value == INT32_MIN)
        {
            // Hardcoded because abs(INT32_MIN) overflows
            ret = appendString(buffer, bufferSize, offset, "-2147483648");
        }
        else
        {
            if (value < 0)
            {
                value = -value;
                buffer[offset++] = '-';
            }

            ret = appendUInt(buffer, bufferSize, offset, static_cast<uint32_t>(value));
        }
    }

    return ret;
}

bool LogFormater::appendUInt(char* buffer, size_t bufferSize, size_t& offset, uint32_t value)
{
    bool ret = false;
    if (offset < bufferSize)
    {
        if (value == 0)
        {
            buffer[offset++] = '0';
            ret = true;
        }
        else
        {
            char digits[10];
            uint32_t index = 0;
            while (value > 0)
            {
                digits[index++] = static_cast<char>('0' + (value % 10));
                value /= 10;
            }

            if (offset + index < bufferSize - 1)
            {
                while (index > 0)
                {
                    buffer[offset++] = digits[--index];
                }
                ret = true;
            }
        }
    }
    return ret;
}

bool LogFormater::appendPointer(char* buffer, size_t bufferSize, size_t& offset, void const* pointer)
{
    auto address = reinterpret_cast<uintptr_t>(pointer);
    return appendHexadecimal(buffer, bufferSize, offset, address);

    // if (appendString(buffer, bufferSize, offset, "0x"))
    // {
    //     auto address = reinterpret_cast<uintptr_t>(pointer);
    //     if (address == 0)
    //     {
    //         ret = appendString(buffer, bufferSize, offset, "0");
    //     }
    //     else
    //     {
    //         char constexpr hexChars[] = "0123456789ABCDEF";
    //         char digits[sizeof(uintptr_t) * 2];
    //
    //         uint32_t index = 0;
    //         while (address > 0)
    //         {
    //             digits[index++] = hexChars[address & 0xF];
    //             address >>= 4;
    //         }
    //
    //         if (offset + index < bufferSize - 1)
    //         {
    //             while (index > 0)
    //             {
    //                 buffer[offset++] = digits[--index];
    //             }
    //             ret = true;
    //         }
    //     }
    // }
}

bool LogFormater::appendHexadecimal(char* buffer, size_t bufferSize, size_t& offset, uint32_t value)
{
    bool ret = false;
    if (appendString(buffer, bufferSize, offset, "0x"))
    {
        if (value == 0)
        {
            ret =  appendString(buffer, bufferSize, offset, "0");
        }
        else
        {
            char constexpr hexadecimalCharacters[] = "0123456789ABCDEF";
            char digits[sizeof(uintptr_t) * 2];

            uint32_t index = 0;
            while (value > 0)
            {
                digits[index++] = hexadecimalCharacters[value & 0xF];
                value >>= 4;
            }

            if (offset + index < bufferSize - 1)
            {
                while (index > 0)
                {
                    buffer[offset++] = digits[--index];
                }
                ret = true;
            }
        }
    }

    return ret;
}

bool LogFormater::appendBinary(char* buffer, size_t bufferSize, size_t& offset, uint32_t value)
{
    bool ret = false;
    if (appendString(buffer, bufferSize, offset, "0b"))
    {
        if (value == 0)
        {
            ret = appendString(buffer, bufferSize, offset, "0");
        }
        else
        {
            char digits[32];
            uint32_t index = 0;
            while (value > 0)
            {
                digits[index++] = (value & 1U) ? '1' : '0';
                value >>= 1;
            }

            if (offset + index < bufferSize - 1)
            {
                while (index > 0)
                {
                    buffer[offset++] = digits[--index];
                }
                ret = true;
            }
        }
    }
    return ret;
}

bool LogFormater::appendTimestamp(char* buffer, size_t const bufferSize, size_t& offset, uint32_t const timestamp)
{
    bool ret = false;
    if (offset < bufferSize - 1)
    {
        buffer[offset++] = '[';

        if (appendUInt(buffer, bufferSize, offset, timestamp))
        {
            if (offset < bufferSize - 1)
            {
                buffer[offset++] = ']';
                ret = true;
            }
        }
    }

    return ret;
}

bool LogFormater::appendFloat(char* buffer, size_t bufferSize, size_t& offset, float value, uint32_t precision)
{
    bool ret = false;
    if (offset < bufferSize - 1)
    {
        if (value == 0.0f)
        {
            ret = appendString(buffer, bufferSize, offset, "0.0");
        }
        else
        {
            if (value < 0.0f)
            {
                buffer[offset++] = '-';
                value = -value;
            }

            auto const integerPart = static_cast<int32_t>(value);
            if (appendInt(buffer, bufferSize, offset, integerPart))
            {
                if (offset < bufferSize - 1)
                {
                    buffer[offset++] = '.';
                    auto const fractionalPart = value - static_cast<float>(integerPart);

                    uint32_t scale = 1;
                    for (uint32_t i = 0; i < precision; ++i)
                    {
                        scale *= 10;
                    }

                    auto const fractionalInt =static_cast<uint32_t>(fractionalPart * static_cast<float>(scale) + 0.5f);
                    uint32_t divisor = scale / 10;

                    bool validOffset = true;
                    while (divisor > 1 && fractionalInt < divisor)
                    {
                        if (offset < bufferSize - 1)
                        {
                            buffer[offset++] = '0';
                            divisor /= 10;
                        }
                        else
                        {
                            validOffset = false;
                            break;
                        }
                    }
                    if (validOffset)
                    {
                        ret = appendUInt(buffer, bufferSize, offset, fractionalInt);
                    }
                }
            }
        }
    }
    return ret;
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
