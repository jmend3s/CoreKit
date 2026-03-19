
#include "TickCounter.h"

void TickCounter::reset()
{
    _tick = 0;
}

void TickCounter::advance()
{
    ++_tick;
}

uint32_t TickCounter::now() const
{
    return _tick;
}
