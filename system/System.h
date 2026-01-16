
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "SchedulableComponent.h"
#include "Scheduler.h"

#include <cstdlib>

class System
{
public:
    System(SchedulableComponent** components,  uint64_t* tickStorage, size_t count);

    void run();

private:
    TickCounter _tickCounter;
    Scheduler _scheduler;

    uint32_t tickPeriodUs = 100;
};


#endif
