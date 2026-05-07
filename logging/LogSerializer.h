
#ifndef __LOG_SERIALIZER_H__
#define __LOG_SERIALIZER_H__

#include "LogArgument.h"


class LogSerializer
{
public:
    static LogArgument serialize(int32_t value);
    static LogArgument serialize(uint32_t value);
    static LogArgument serialize(float value);
    static LogArgument serialize(char const* value);
    static LogArgument serialize(void const* value);
};


#endif
