
#include "TimeSource.h"

#include <zephyr/kernel.h>
#include <zephyr/sys/time_units.h>


uint64_t TimeSource::now() const
{
    return k_ticks_to_us_floor64(k_uptime_ticks());
}

void TimeSource::sleep(uint32_t const us)
{
    k_sleep(K_USEC(us));
}