
#ifndef __ADC_H__
#define __ADC_H__

#include "Component.h"

#include <zephyr/drivers/adc.h>


class Adc : public Component
{
public:
    Adc(adc_dt_spec const& spec);

    void initialize() override;
    void update() override;

    int32_t lastReading() const;

private:
    adc_dt_spec _spec;
    adc_sequence _sequence;

    int32_t _readValue;
    int16_t _buffer;
};

#endif