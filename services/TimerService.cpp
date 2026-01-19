
#include "TimerService.h"

#include "SystemClock.h"


TimerService::TimerService()
    : _1ms(10)
    , _10ms(100)
    , _20ms(200)
    , _100ms(1000)
    , _1000ms(10000)
{
}
void TimerService::initialize()
{
    uint32_t const now = SystemClock::currentTick();

    _1ms.reset(now);
    _10ms.reset(now);
    _20ms.reset(now);
    _100ms.reset(now);
    _1000ms.reset(now);
}

void TimerService::update()
{
    uint32_t const tick = SystemClock::currentTick();

    _1ms.update(tick);
    _10ms.update(tick);
    _20ms.update(tick);
    _100ms.update(tick);
    _1000ms.update(tick);
}

uint32_t TimerService::periodTick() const
{
    return 1;
}

bool TimerService::ms1() const
{
    return _1ms.elapsed();
}

bool TimerService::ms10() const
{
    return _10ms.elapsed();
}

bool TimerService::ms20() const
{
    return _20ms.elapsed();
}

bool TimerService::ms100() const
{
    return _100ms.elapsed();
}

bool TimerService::ms1000() const
{
    return _1000ms.elapsed();
}
