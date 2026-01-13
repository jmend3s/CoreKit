
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "SchedulableComponent.h"
#include "Scheduler.h"

#include <cstdlib>


class System
{
public:
    System(SchedulableComponent** components,  uint64_t* lastTickStorage, size_t count);

    void run();

private:
    TickCounter _tickCounter;
    Scheduler _scheduler;
};

class SystemTick
{
public:
    static constexpr uint32_t periodUs()
    {
        return 100;
    }
};

#endif
