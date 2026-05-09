
#ifndef __UINT32_SERIALIZER_H__
#define __UINT32_SERIALIZER_H__

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
