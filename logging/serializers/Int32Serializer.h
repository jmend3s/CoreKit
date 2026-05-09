
#ifndef __SERIALIZER_INT32_H__
#define __SERIALIZER_INT32_H__

#include "LogSerializer.h"
#include "LogArgument.h"

#include <cstdint>


template<>
struct LogSerializer<int32_t>
{
    static LogArgument serialize(int32_t const value)
    {
        LogArgument argument {};
        argument.type = LogArgumentType::Int32;
        argument.intValue = value;
        return argument;
    }
};


#endif
