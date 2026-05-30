
#include "AdcWrapper.h"

#include <zephyr/drivers/adc.h>


struct AdcWrapper::Sequence
{
    adc_sequence sequence {};
    int16_t buffer = 0;
};

static adc_dt_spec const* toDt(AdcWrapper::SpecHandle& spec)
{
    return reinterpret_cast<adc_dt_spec const*>(spec.spec());
}

AdcWrapper::AdcWrapper(SpecHandle& spec)
    : _spec(spec)
    , _sequence(new Sequence{})
{
    _sequence->sequence = {};
    _sequence->sequence.buffer = 0;
    _sequence->sequence.buffer_size = 0;
}

AdcWrapper::~AdcWrapper()
{
    delete _sequence;
}

bool AdcWrapper::isReady() const
{
    return adc_is_ready_dt(toDt(_spec));
}

int AdcWrapper::channelSetup() const
{
    return adc_channel_setup_dt(toDt(_spec));
}

int AdcWrapper::sequenceInit()
{
    _sequence->sequence = {
        .buffer = &_sequence->buffer,
        .buffer_size = sizeof(_sequence->buffer)
    };

    return adc_sequence_init_dt(toDt(_spec), &_sequence->sequence);
}

int32_t AdcWrapper::read() const
{
    adc_read_dt(toDt(_spec), &_sequence->sequence);
    return _sequence->buffer;
}
