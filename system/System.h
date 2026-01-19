
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "ISystemTime.h"
#include "SchedulableComponent.h"
#include "Scheduler.h"


class System
{
public:
    System(SchedulableComponent** components,  uint64_t* tickStorage, size_t count, ISystemTime& time);

    void initialize();
    void run();
    void runOnce();

private:
    ISystemTime& _time;
    TickCounter _tickCounter;
    Scheduler _scheduler;

    uint32_t _tickPeriodUs = 100;   // No no
};


#endif
