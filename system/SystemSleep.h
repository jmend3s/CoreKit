
#ifndef __SYSTEM_SLEEP_H__
#define __SYSTEM_SLEEP_H__

#include <stdint.h>


class SystemSleep
{
public:
    static void sleepUs(uint32_t us);
    static void sleepUntilUs(uint64_t deadline);
};


#endif
