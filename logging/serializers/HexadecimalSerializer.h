
#ifndef __HEXADECIMAL_SERIALIZER_H__
#define __HEXADECIMAL_SERIALIZER_H__

#include "types/Hexadecimal.h"
#include "LogSerializer.h"
#include "LogArgument.h"



template<>
struct LogSerializer<Hexadecimal>
{
    static LogArgument serialize(Hexadecimal const value)
    {
        LogArgument arg {};
        arg.type = LogArgumentType::Hexadecimal;
        arg.uintValue = value.value;
        return arg;
    }
};


#endif
