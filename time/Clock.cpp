
#include "Clock.h"


TickCounter* Clock::_tickCounter = nullptr;

uint32_t Clock::currentTick()
{
    return _tickCounter->now();
}

void Clock::bind(TickCounter* counter)
{
    _tickCounter = counter;
}
