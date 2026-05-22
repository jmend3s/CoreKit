
#ifndef __BINARY_SERIALIZER_H__
#define __BINARY_SERIALIZER_H__

#include "LogSerializer.h"
#include "LogArgument.h"


struct Binary32
{
    uint32_t value;
};

template<>
struct LogSerializer<Binary32>
{
    static LogArgument serialize(Binary32 const value)
    {
        LogArgument arg {};
        arg.type = LogArgumentType::Binary32;
        arg.uintValue = value.value;
        return arg;
    }
};


#endif
