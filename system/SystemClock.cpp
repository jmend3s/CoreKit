
#include "SystemClock.h"

#include <zephyr/kernel.h>


TickCounter* SystemClock::_tickCounter = nullptr;

uint32_t SystemClock::currentTick()
{
    return _tickCounter->now();
}

void SystemClock::bind(TickCounter* counter)
{
    _tickCounter = counter;
}
