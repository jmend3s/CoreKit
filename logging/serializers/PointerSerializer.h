
#ifndef __POINTER_SERIALIZER_H__
#define __POINTER_SERIALIZER_H__

#include "LogSerializer.h"
#include "LogArgument.h"


template<>
struct LogSerializer<void*>
{
    static LogArgument serialize(void const* value)
    {
        LogArgument argument;
        argument.type = LogArgumentType::Pointer;
        argument.pointerValue = value;
        return argument;
    }
};


#endif
