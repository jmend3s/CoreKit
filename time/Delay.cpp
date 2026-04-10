
#include "Delay.h"

#include <zephyr/kernel.h>


void Delay::ms(int duration)
{
    k_sleep(K_MSEC(duration));
}
