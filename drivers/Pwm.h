
#ifndef __PWM_H__
#define __PWM_H__

#include "HalPwm.h"


using PwmSpec = HalPwm::Spec;
class Pwm
{
public:
    Pwm(PwmSpec& spec);

    bool setPulseNs(uint32_t pulseNs);
    bool setPulseUs(uint32_t pulseUs);
    bool setDutyCycle(float duty);

    uint32_t periodNs();

private:
    HalPwm _hal;
};


#endif
