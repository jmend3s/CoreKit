
#include "System.h"
#include "SystemClock.h"
#include "SystemSleep.h"

#include <zephyr/kernel.h>


// This should probably not receive lastTickStorage
System::System(SchedulableComponent** components, uint64_t* lastTickStorage, size_t count)
    : _scheduler(components, lastTickStorage, count, _tickCounter)
{
}

void System::run()
{
    _scheduler.initialize();

    while (true)
    {
        uint64_t nextTickUs = SystemClock::nowUs();
        _scheduler.runOnce();

        nextTickUs += SystemTick::periodUs();
        SystemSleep::sleepUntilUs(nextTickUs);

        _tickCounter.advance();
    }
}
