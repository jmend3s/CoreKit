
#include "TimerTick.h"


TimerTick::TimerTick(uint32_t const periodTicks)
    : _periodTicks(periodTicks)
    , _lastTick(0)
    , _elapsed(false)
{
}

void TimerTick::reset(uint32_t const currentTick)
{
    _lastTick = currentTick;
    _elapsed = false;
}

void TimerTick::update(uint32_t const currentTick)
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

bool TimerTick::elapsed() const
{
    return _elapsed;
}