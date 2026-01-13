
#include "SystemSleep.h"
#include "SystemClock.h"

#include <zephyr/kernel.h>


void SystemSleep::sleepUs(uint32_t const us)
{
    k_sleep(K_USEC(us));
}

void SystemSleep::sleepUntilUs(uint64_t const deadline)
{
    uint64_t const now = SystemClock::nowUs();
    if (deadline > now)
    {
        sleepUs(static_cast<uint32_t>(deadline - now));
    }
}
