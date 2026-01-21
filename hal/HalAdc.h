
#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__


#include "HalSpecHandle.h"


class HalAdc
{
public:
    class Spec : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    HalAdc(Spec& spec);

    bool isReady() const;
    int channelSetup() const;
    int sequenceInit();
    int32_t read() const;

private:
    struct Sequence;

    Spec& _spec;
    Sequence* _sequence;
};


#endif
