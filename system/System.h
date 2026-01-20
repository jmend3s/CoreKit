
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "ISystemTime.h"
#include "SchedulableComponent.h"
#include "Scheduler.h"


class System
{
public:
    System(SchedulableComponent** components,  uint64_t* tickStorage, size_t count, ISystemTime& time, uint32_t tickPeriodUs = 100);

    void initialize();
    void run();
    void runOnce();
    void pace();

private:
    ISystemTime& _time;
    TickCounter _tickCounter;
    Scheduler _scheduler;

    uint32_t _tickPeriodUs;
    uint64_t _nextTickUs;
};


#endif
