
#ifndef __LOG_SERIALIZER_H__
#define __LOG_SERIALIZER_H__


template<class T>
struct LogSerializer
{
    static_assert(sizeof(T) == 0, "Unsupported log serialization type");
};


#endif
