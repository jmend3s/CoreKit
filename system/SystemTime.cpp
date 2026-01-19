
#include "SystemTime.h"

#include <zephyr/kernel.h>
#include <zephyr/sys/time_units.h>


uint64_t SystemTime::now() const
{
    return k_ticks_to_us_floor64(k_uptime_ticks());
}

void SystemTime::sleep(uint32_t const us)
{
    k_sleep(K_USEC(us));
}