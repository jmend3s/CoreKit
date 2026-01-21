
#include "HalAdc.h"

#include <zephyr/drivers/adc.h>


struct HalAdc::Sequence
{
    adc_sequence sequence;
    int16_t buffer = 0;
};

static adc_dt_spec const* toDt(HalAdc::Spec& spec)
{
    return reinterpret_cast<adc_dt_spec const*>(spec.spec());
}

HalAdc::HalAdc(Spec& spec)
    : _spec(spec)
{
    static Sequence sequence;
    _sequence = &sequence;
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
