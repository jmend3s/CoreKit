
#ifndef __HAL_PWM_H__
#define __HAL_PWM_H__

#include "HalSpecHandle.h"

#include <cstdint>


class HalPwm
{
public:
    class Spec : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    HalPwm(Spec& spec);

    bool isReady();
    int setPulse(uint32_t pulseNs);
    uint32_t period();

private:
    Spec& _spec;
};


#endif
