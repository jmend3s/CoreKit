
#include "SystemClock.h"

#include <zephyr/kernel.h>


uint64_t SystemClock::nowUs()
{
    return k_ticks_to_us_floor64(k_uptime_ticks());
}
