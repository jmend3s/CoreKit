
#include "LogSerializer.h"

LogArgument LogSerializer::serialize(int32_t value)
{
    LogArgument argument {};

    argument.type = LogArgumentType::Int32;
    argument.intValue = value;

    return argument;
}

LogArgument LogSerializer::serialize(uint32_t value)
{
    LogArgument argument {};

    argument.type = LogArgumentType::UInt32;
    argument.uintValue = value;

    return argument;
}

LogArgument LogSerializer::serialize(float value)
{
    LogArgument argument {};

    argument.type = LogArgumentType::Float;
    argument.floatValue = value;

    return argument;
}

LogArgument LogSerializer::serialize(char const* value)
{
    LogArgument argument {};

    argument.type = LogArgumentType::String;
    argument.stringValue = value;

    return argument;
}

LogArgument LogSerializer::serialize(void const* value)
{
    LogArgument argument {};

    argument.type = LogArgumentType::Pointer;
    argument.pointerValue = value;

    return argument;
}
