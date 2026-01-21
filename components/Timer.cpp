
#include "Timer.h"


Timer::Timer(uint32_t const periodTicks)
    : _periodTicks(periodTicks)
    , _lastTick(0)
    , _elapsed(false)
{
}

void Timer::reset(uint32_t const currentTick)
{
    _lastTick = currentTick;
    _elapsed = false;
}

void Timer::update(uint32_t const currentTick)
{
    if (currentTick - _lastTick >= _periodTicks)
    {
        _lastTick = currentTick;
        _elapsed = true;
    }
    else
    {
        _elapsed = false;
    }
}

bool Timer::elapsed() const
{
    return _elapsed;
}