
#ifndef __SERIALIZER_UINT32_H__
#define __SERIALIZER_UINT32_H__

#include "LogSerializer.h"
#include "LogArgument.h"

#include <cstdint>


template<>
struct LogSerializer<uint32_t>
{
    static LogArgument serialize(uint32_t const value)
    {
        LogArgument argument;
        argument.type = LogArgumentType::UInt32;
        argument.uintValue = value;
        return argument;
    }
};


#endif
