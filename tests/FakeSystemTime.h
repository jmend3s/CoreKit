
#ifndef __FAKE_SYSTEM_TIME_H__
#define __FAKE_SYSTEM_TIME_H__

#include "ISystemTime.h"


class FakeSystemTime : public ISystemTime
{
public:
    uint64_t now() const override;
    void sleep(uint32_t duration) override;
    void advance(uint64_t period);

private:
    uint64_t _now = 0;
};


#endif
