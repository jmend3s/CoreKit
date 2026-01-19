
#ifndef __SYSTEM_CLOCK_H__
#define __SYSTEM_CLOCK_H__

#include "TickCounter.h"

#include <cstdint>


class SystemClock
{
public:
    static uint32_t currentTick();
    static void bind(TickCounter* counter);

private:
    static TickCounter* _tickCounter;
};


#endif
