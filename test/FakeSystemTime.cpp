
#include "FakeSystemTime.h"


uint64_t FakeSystemTime::now() const
{
    return _now;
}

void FakeSystemTime::sleep(uint32_t const duration)
{
    slept_us += duration;
    _now += duration;
}

void FakeSystemTime::advance(uint64_t period)
{
    _now += period;
}
