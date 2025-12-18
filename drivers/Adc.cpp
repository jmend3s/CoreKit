
#include "Adc.h"

Adc::Adc(adc_dt_spec const& spec)
    : _spec(spec)
    , _buffer(0)
{
}

void Adc::initialize()
{
    adc_is_ready_dt(&_spec);
    adc_channel_setup_dt(&_spec);

    adc_sequence const sequence
    {
        .buffer = &_buffer,
        .buffer_size = sizeof(_buffer)
    };

    _sequence = sequence;
    adc_sequence_init_dt(&_spec, &_sequence);
}

void Adc::update()
{
}

void Adc::read()
{
    adc_read_dt(&_spec, &_sequence);
    _readValue = _buffer;
}

int32_t Adc::lastReading() const
{
    return _readValue;
}
