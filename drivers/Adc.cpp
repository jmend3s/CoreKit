
#include "Adc.h"

Adc::Adc(AdcSpec& spec)
    : _hal(spec)
{
}

void Adc::initialize()
{
    if (_hal.isReady())
    {
        _hal.channelSetup();
        _hal.sequenceInit();
    }
}

void Adc::read()
{
    _readValue = _hal.read();
}

int32_t Adc::lastReading() const
{
    return _readValue;
}
