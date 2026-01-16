
#include "System.h"
#include "SystemClock.h"
#include "SystemSleep.h"
#include "SystemTime.h"

#include <zephyr/kernel.h>


System::System(SchedulableComponent** components, uint64_t* tickStorage, size_t count)
    : _scheduler(components, tickStorage, count, _tickCounter)
{
}

void System::run()
{
    SystemTime::bind(&_tickCounter);
    _scheduler.initialize();

    while (true)
    {
        uint64_t nextTickUs = SystemClock::nowUs();
        _scheduler.runOnce();

        nextTickUs += tickPeriodUs;
        SystemSleep::sleepUntilUs(nextTickUs);

        _tickCounter.advance();
    }
}
