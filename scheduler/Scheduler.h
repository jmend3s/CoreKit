
#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "SchedulableComponent.h"
#include "../system/TickCounter.h"

#include <cstdlib>


class Scheduler
{
public:
    Scheduler(SchedulableComponent** components, uint64_t* lastTickStorage,
        size_t count, TickCounter& tickCounter);

    void initialize();
    void runOnce();

private:
    SchedulableComponent** _components;
    uint64_t* _lastTick;
    size_t _count;
    TickCounter& _tickCounter;
};


#endif
