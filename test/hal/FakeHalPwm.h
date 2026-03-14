
#ifndef __FAKE_HAL_PWM_H__
#define __FAKE_HAL_PWM_H__

#include <cstdint>


struct FakePwmState
{
    bool ready = true;

    uint32_t period_ns = 20'000'000;
    uint32_t pulse_ns = 0;

    int setPulseCalls = 0;
};


#endif
