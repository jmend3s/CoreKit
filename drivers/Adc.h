
#ifndef __ADC_H__
#define __ADC_H__

#include "zephyr/AdcWrapper.h"


using AdcSpec = AdcWrapper::SpecHandle;
class Adc
{
public:
    Adc(AdcSpec& spec);

    void initialize();
    void read();

    int32_t lastReading() const;

private:
    int32_t _readValue;
    AdcWrapper _hal;
};

#endif