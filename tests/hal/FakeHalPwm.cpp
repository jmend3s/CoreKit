
#include "FakeHalPwm.h"
#include "HalPwm.h"


static FakePwmState* stateFrom(HalSpecHandle& handle)
{
    return reinterpret_cast<FakePwmState*>(handle.spec());
}

HalPwm::HalPwm(Spec& spec)
    : _spec(spec)
{
}

bool HalPwm::isReady()
{
    return stateFrom(_spec)->ready;
}

int HalPwm::setPulse(uint32_t pulseNs)
{
    auto* state = stateFrom(_spec);
    state->pulse_ns = pulseNs;
    state->setPulseCalls++;
    return 0;
}

uint32_t HalPwm::period()
{
    return stateFrom(_spec)->period_ns;
}