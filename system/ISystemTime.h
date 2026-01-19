
#ifndef __I_SYSTEM_TIME_H__
#define __I_SYSTEM_TIME_H__

#include <cstdint>


class ISystemTime
{
public:
    virtual ~ISystemTime() = default;

    virtual  uint64_t now() const = 0;
    virtual void sleep(uint32_t duration) = 0;
};


#endif
