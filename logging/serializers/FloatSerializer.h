
#ifndef __FLOAT_SERIALIZER_H__
#define __FLOAT_SERIALIZER_H__

#include "LogSerializer.h"
#include "LogArgument.h"


template<>
struct LogSerializer<float>
{
    static LogArgument serialize(float const value)
    {
        LogArgument argument;
        argument.type = LogArgumentType::Float;
        argument.uintValue = value;
        return argument;
    }
};


#endif
