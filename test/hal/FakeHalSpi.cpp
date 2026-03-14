
#include "FakeHalSpi.h"
#include "HalSpi.h"


static FakeSpiState* stateFrom(HalSpi::SpecHandle& handle)
{
    return reinterpret_cast<FakeSpiState*>(handle.spec());
}

HalSpi::HalSpi(SpecHandle& spec)
    : _spec(spec)
{
}

bool HalSpi::isReady()
{
    return stateFrom(_spec)->ready;
}

int HalSpi::transceive(uint8_t* tx, uint8_t* rx, uint16_t const size)
{
    auto* state = stateFrom(_spec);

    state->transceiveCalls++;
    state->lastSize = size;

    if (tx)
    {
        state->lastTx = *tx;
    }

    if (rx)
    {
        *rx = state->rx;
    }

    return 0;
}
