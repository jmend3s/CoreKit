
#include "TimerService.h"

TimerService::TimerService(TickCounter& _tickCounter)
    : _tickCounter(_tickCounter)
    , _1ms(1)
    , _10ms(10)
    , _20ms(20)
    , _100ms(100)
{
}
void TimerService::initialize()
{
    uint32_t now = _tickCounter.now();

    _1ms.reset(now);
    _10ms.reset(now);
    _20ms.reset(now);
    _100ms.reset(now);
}

void TimerService::update()
{
    uint32_t tick = _tickCounter.now();

    _1ms.update(tick);
    _10ms.update(tick);
    _20ms.update(tick);
    _100ms.update(tick);
}

uint32_t TimerService::periodTicks() const
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
