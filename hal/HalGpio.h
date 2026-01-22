
#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#include "HalSpecHandle.h"


class HalGpio
{
public:
    class SpecHandle : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    HalGpio(SpecHandle& spec);

    bool isReady();
    int pinConfigure(bool mode);
    int pinSet(bool set);
    int toggle();
    int read() const;

private:
    SpecHandle& _spec;
};


#endif
