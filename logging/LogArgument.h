
#ifndef __LOG_ARGUMENT_H__
#define __LOG_ARGUMENT_H__

#include <cstdint>


enum class LogArgumentType : uint8_t
{
    Float,
    Int32,
    UInt32,
    String,
    Pointer
};


struct LogArgument
{
    LogArgumentType type;

    union
    {
        float floatValue;
        int32_t intValue;
        uint32_t uintValue;
        char const* stringValue;
        void const* pointerValue;
    };
};


#endif
