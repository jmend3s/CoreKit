
#ifndef __PWM_H__
#define __PWM_H__

#include "zephyr/PwmWrapper.h"


using PwmSpec = PwmWrapper::Spec;
class Pwm
{
public:
    Pwm(PwmSpec& spec);

    bool setPulseNs(uint32_t pulseNs);
    bool setPulseUs(uint32_t pulseUs);
    bool setDutyCycle(float duty);

    uint32_t periodNs();

private:
    PwmWrapper _hal;
};


#endif
