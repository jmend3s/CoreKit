
#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "SchedulableComponent.h"

#include <cstdlib>


class Scheduler
{
public:
    Scheduler(SchedulableComponent** components, size_t count);

    void initialize() const;
    void runOnce() const;

private:
    SchedulableComponent** _components;
    size_t _count;
    uint64_t* _lastRun;
};


#endif
