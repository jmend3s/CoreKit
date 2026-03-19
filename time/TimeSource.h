
#ifndef __TIME_SOURCE_H__
#define __TIME_SOURCE_H__

#include "ITimeSource.h"

#include <cstdint>


class TimeSource : public ITimeSource
{
public:
    uint64_t now() const override;
    void sleep(uint32_t us) override;
};


#endif
