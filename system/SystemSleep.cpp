
#include "SystemSleep.h"

#include <zephyr/kernel.h>


void SystemSleep::sleepUs(uint32_t const us)
{
    k_sleep(K_USEC(us));
}
