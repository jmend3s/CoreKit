
#include "Delay.h"

#include <zephyr/kernel.h>


void Delay::us(int const duration)
{
    k_sleep(K_USEC(duration));
}

void Delay::ms(int const duration)
{
    k_sleep(K_MSEC(duration));
}
