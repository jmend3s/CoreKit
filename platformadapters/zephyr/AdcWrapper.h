
#ifndef __ADC_WRAPPER_H__
#define __ADC_WRAPPER_H__

#include "HalSpecHandle.h"


class AdcWrapper
{
public:
    class SpecHandle : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    AdcWrapper(SpecHandle& spec);
    ~AdcWrapper();

    AdcWrapper(const AdcWrapper&) = delete;
    AdcWrapper& operator=(const AdcWrapper&) = delete;

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
