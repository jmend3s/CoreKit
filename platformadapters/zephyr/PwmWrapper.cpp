
#include "PwmWrapper.h"

#include <zephyr/drivers/pwm.h>


static pwm_dt_spec const* toDt(PwmWrapper::Spec& spec)
{
    return reinterpret_cast<pwm_dt_spec const*>(spec.spec());
}

PwmWrapper::PwmWrapper(Spec& spec)
    : _spec(spec)
{
}

bool PwmWrapper::isReady()
{
    return pwm_is_ready_dt(toDt(_spec));
}

int PwmWrapper::setPulse(uint32_t const pulseNs)
{
    return pwm_set_dt(toDt(_spec), toDt(_spec)->period, pulseNs);
}

uint32_t PwmWrapper::period()
{
    return toDt(_spec)->period;
}
