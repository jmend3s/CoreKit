
#ifndef __HAL_WRAPPER_H__
#define __HAL_WRAPPER_H__

#include "HalSpecHandle.h"


class GpioWrapper
{
public:
    class SpecHandle : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    GpioWrapper(SpecHandle& spec);

    bool isReady();
    int pinConfigure(bool mode);
    int pinSet(bool set);
    int toggle();
    int read() const;

private:
    SpecHandle& _spec;
};


#endif
