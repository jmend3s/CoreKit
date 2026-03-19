
#include "Adc.h"

Adc::Adc(AdcSpec& spec)
    : _adc(spec)
{
}

void Adc::initialize()
{
    if (_adc.isReady())
    {
        _adc.channelSetup();
        _adc.sequenceInit();
    }
}

void Adc::read()
{
    _readValue = _adc.read();
}

int32_t Adc::lastReading() const
{
    return _readValue;
}
