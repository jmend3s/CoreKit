
#include "Pwm.h"


Pwm::Pwm(PwmSpec& spec)
    : _hal(spec)
{
}

bool Pwm::setPulseNs(uint32_t const pulseNs)
{
    auto const error = _hal.setPulse(pulseNs);
    return error == 0;
}

bool Pwm::setPulseUs(uint32_t const pulseUs)
{
    uint32_t const pulseNs = pulseUs * 1000U;
    return setPulseNs(pulseNs);
}

bool Pwm::setDutyCycle(float duty)
{
    if (duty < 0.0f)
    {
        duty = 0.0f;
    }
    else if (duty > 1.0f)
    {
        duty = 1.0f;
    }

    auto const temp = duty * static_cast<float>(periodNs());
    auto const pulseNs = static_cast<uint32_t>(temp);

    return setPulseNs(pulseNs);
}

uint32_t Pwm::periodNs()
{
    return _hal.period();
}
