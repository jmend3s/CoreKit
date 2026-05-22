
#ifndef __HEXADECIMAL_SERIALIZER_H__
#define __HEXADECIMAL_SERIALIZER_H__

#include "LogSerializer.h"
#include "LogArgument.h"


struct Hex32
{
    uint32_t value;
};

template<>
struct LogSerializer<Hex32>
{
    static LogArgument serialize(Hex32 const value)
    {
        LogArgument arg {};
        arg.type = LogArgumentType::Hexadecimal;
        arg.uintValue = value.value;
        return arg;
    }
};


#endif
