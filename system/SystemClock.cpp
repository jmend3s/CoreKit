
#include "SystemClock.h"


TickCounter* SystemClock::_tickCounter = nullptr;

uint32_t SystemClock::currentTick()
{
    return _tickCounter->now();
}

void SystemClock::bind(TickCounter* counter)
{
    _tickCounter = counter;
}
