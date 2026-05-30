
#ifndef __PWM_WRAPPER_H__
#define __PWM_WRAPPER_H__

#include "HalSpecHandle.h"

#include <cstdint>


class PwmWrapper
{
public:
    class Spec : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    PwmWrapper(Spec& spec);

    bool isReady();
    int setPulse(uint32_t pulseNs);
    uint32_t period();

private:
    Spec& _spec;
};


#endif
