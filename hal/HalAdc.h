
#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__


#include "HalSpecHandle.h"


class HalAdc
{
public:
    class SpecHandle : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    HalAdc(SpecHandle& spec);
    ~HalAdc();

    HalAdc(const HalAdc&) = delete;
    HalAdc& operator=(const HalAdc&) = delete;

    bool isReady() const;
    int channelSetup() const;
    int sequenceInit();
    int32_t read() const;

private:
    struct Sequence;

    SpecHandle& _spec;
    Sequence* _sequence;
};


#endif
