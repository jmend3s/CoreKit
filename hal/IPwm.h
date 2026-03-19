
#ifndef __I_PWM_H__
#define __I_PWM_H__

#include<cstdint>


class IPwm
{
public:
    virtual bool setPulseNs(uint32_t pulseNs) = 0;
    virtual bool setPulseUs(uint32_t pulseUs) = 0;
    virtual bool setDutyCycle(float duty) = 0;
    virtual uint32_t periodNs() = 0;
    virtual ~IPwm() = default;
};


#endif
