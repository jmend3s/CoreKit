
#include "HalAdc.h"
#include "FakeHalAdc.h"


static FakeAdcState* stateFrom(HalAdc::SpecHandle& handle)
{
    return reinterpret_cast<FakeAdcState*>(handle.spec());
}

HalAdc::HalAdc(SpecHandle& spec)
    : _spec(spec)
{
}

HalAdc::~HalAdc()
{
}

bool HalAdc::isReady() const
{
    return stateFrom(_spec)->ready;
}

int HalAdc::channelSetup() const
{
    stateFrom(_spec)->channelSet = true;
    return 0;
}

int HalAdc::sequenceInit()
{
    stateFrom(_spec)->sequenceInitialized = true;
    return 0;
}

int32_t HalAdc::read() const
{
    auto* state = stateFrom(_spec);
    state->readCalled = true;
    return state->readValue;
}
