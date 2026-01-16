
#include "TimerMs.h"


#include <zephyr/kernel.h>


TimerMs::TimerMs(uint32_t const periodMs)
    : _periodMs(periodMs)
    , _lastTick(0)
    , _elapsed(false)
{
}

void TimerMs::initialize()
{
    _lastTick = k_uptime_get();
    _elapsed = false;
}

void TimerMs::update()
{
    auto const now = k_uptime_get();
    if (now - _lastTick >= _periodMs)
    {
        _lastTick = now;
        _elapsed = true;
    }
    else
    {
        _elapsed = false;
    }
}

bool TimerMs::elapsed() const
{
    return _elapsed;
}

uint32_t TimerMs::period() const
{
    return _periodMs;
}