
#include "HalPwm.h"

#include <zephyr/drivers/pwm.h>


static const pwm_dt_spec* toDt(HalPwm::Spec& spec)
{
    return reinterpret_cast<pwm_dt_spec const*>(spec.spec());
}

HalPwm::HalPwm(Spec& spec)
    : _spec(spec)
{
}

bool HalPwm::isReady()
{
    return pwm_is_ready_dt(toDt(_spec));
}

int HalPwm::setPulse(uint32_t const pulseNs)
{
    return pwm_set_dt(toDt(_spec), toDt(_spec)->period, pulseNs);
}

uint32_t HalPwm::period()
{
    return toDt(_spec)->period;
}
