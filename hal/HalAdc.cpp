
#include "HalAdc.h"

#include <zephyr/drivers/adc.h>


struct HalAdc::Sequence
{
    adc_sequence sequence {};
    int16_t buffer = 0;
};

static adc_dt_spec const* toDt(HalAdc::SpecHandle& spec)
{
    return reinterpret_cast<adc_dt_spec const*>(spec.spec());
}

HalAdc::HalAdc(SpecHandle& spec)
    : _spec(spec)
    , _sequence(new Sequence{})
{
    _sequence->sequence = {};
    _sequence->sequence.buffer = 0;
    _sequence->sequence.buffer_size = 0;
}

HalAdc::~HalAdc()
{
    delete _sequence;
}

bool HalAdc::isReady() const
{
    return adc_is_ready_dt(toDt(_spec));
}

int HalAdc::channelSetup() const
{
    return adc_channel_setup_dt(toDt(_spec));
}

int HalAdc::sequenceInit()
{
    _sequence->sequence = {
        .buffer = &_sequence->buffer,
        .buffer_size = sizeof(_sequence->buffer)
    };

    return adc_sequence_init_dt(toDt(_spec), &_sequence->sequence);
}

int32_t HalAdc::read() const
{
    adc_read_dt(toDt(_spec), &_sequence->sequence);
    return _sequence->buffer;
}
