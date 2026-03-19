
#ifndef __I_TIME_SOURCE_H__
#define __I_TIME_SOURCE_H__

#include <cstdint>


class ITimeSource
{
public:
    virtual ~ITimeSource() = default;

    virtual uint64_t now() const = 0;
    virtual void sleep(uint32_t duration) = 0;
};


#endif
