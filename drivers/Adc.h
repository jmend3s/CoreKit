
#ifndef __ADC_H__
#define __ADC_H__

#include "HalAdc.h"


using AdcSpec = HalAdc::Spec;
class Adc
{
public:
    Adc(AdcSpec& spec);

    void initialize();
    void read();

    int32_t lastReading() const;

private:
    int32_t _readValue;
    HalAdc _hal;
};

#endif