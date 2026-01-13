
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "SchedulableComponent.h"
#include "Scheduler.h"

#include <cstdlib>


class Application
{
public:
    Application(SchedulableComponent** components, size_t count);

    void run();

private:
    Scheduler _scheduler;
};


#endif
