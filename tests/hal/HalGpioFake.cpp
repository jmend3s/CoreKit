
#include "HalGpio.h"
#include "HalGpioFake.h"


static FakeGpioState* stateFrom(HalGpio::SpecHandle& handle)
{
    return reinterpret_cast<FakeGpioState*>(handle.spec());
}

HalGpio::HalGpio(SpecHandle& spec)
    : _spec(spec)
{
}

bool HalGpio::isReady()
{
    return stateFrom(_spec)->ready;
}

int HalGpio::pinConfigure(bool mode)
{
    auto* state = stateFrom(_spec);
    state->configured = true;
    state->outputMode = mode;
    return 0;
}

int HalGpio::pinSet(bool set)
{
    auto* state = stateFrom(_spec);
    state->level = set;
    state->setCalls++;
    return 0;
}

int HalGpio::toggle()
{
    auto* state = stateFrom(_spec);
    state->level = !state->level;
    state->toggleCalls++;
    return 0;
}

int HalGpio::read() const
{
    return stateFrom(_spec)->level;
}
