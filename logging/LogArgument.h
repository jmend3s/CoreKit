
#ifndef __LOG_ARGUMENT_H__
#define __LOG_ARGUMENT_H__

#include <cstdint>


enum class LogArgumentType : uint8_t
{
    Int32,
    UInt32,
    Float,
    String,
    Pointer
};


struct LogArgument
{
    LogArgumentType type;

    union
    {
        int32_t intValue;
        uint32_t uintValue;
        float floatValue;
        char const* stringValue;
        void const* pointerValue;
    };
};


#endif
