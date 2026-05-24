
#ifndef __STRING_SERIALIZER_H__
#define __STRING_SERIALIZER_H__

#include "LogSerializer.h"
#include "LogArgument.h"

#include <cstddef>


template<>
struct LogSerializer<char const*>
{
    static LogArgument serialize(char const* value)
    {
        LogArgument argument {};
        argument.type = LogArgumentType::String;
        argument.stringValue = value;
        return argument;
    }
};

template<size_t N>
struct LogSerializer<char[N]>
    : LogSerializer<char const*>
{
};

template<size_t N>
struct LogSerializer<char const[N]>
    : LogSerializer<char const*>
{
};


#endif
