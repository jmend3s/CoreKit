
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "TickCounter.h"

#include <cstdint>


class Clock
{
public:
    static uint32_t currentTick();
    static void bind(TickCounter* counter);

private:
    static TickCounter* _tickCounter;
};


#endif
