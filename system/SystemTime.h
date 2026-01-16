
#ifndef __SYSTEM_TIME_H__
#define __SYSTEM_TIME_H__

#include "TickCounter.h"

#include <cstdint>


class SystemTime
{
public:
    static uint32_t currentTick()
    {
        return _tickCounter->now();
    }

    static void bind(TickCounter* counter)
    {
        _tickCounter = counter;
    }

private:
    static TickCounter* _tickCounter;
};


#endif
