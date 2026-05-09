
#ifndef __SERIALIZER_STRING_H__
#define __SERIALIZER_STRING_H__

#include "LogSerializer.h"
#include "LogArgument.h"


template<>
struct LogSerializer<char*>
{
    static LogArgument serialize(char const* value)
    {
        LogArgument argument;
        argument.type = LogArgumentType::String;
        argument.stringValue = value;
        return argument;
    }
};


#endif
