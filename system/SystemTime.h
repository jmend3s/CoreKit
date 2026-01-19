
#ifndef __SYSTEM_TIME_H__
#define __SYSTEM_TIME_H__

#include "ISystemTime.h"

#include <cstdint>


class SystemTime : public ISystemTime
{
public:
    uint64_t now() const override;
    void sleep(uint32_t us) override;
};


#endif
