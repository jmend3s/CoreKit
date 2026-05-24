
#ifndef __BINARY_SERIALIZER_H__
#define __BINARY_SERIALIZER_H__

#include "types/Binary.h"
#include "LogSerializer.h"
#include "LogArgument.h"


template<>
struct LogSerializer<Binary>
{
    static LogArgument serialize(Binary const value)
    {
        LogArgument argument {};
        argument.type = LogArgumentType::Binary;
        argument.uintValue = value.value;
        return argument;
    }
};


#endif
