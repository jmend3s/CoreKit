
#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#include "HalSpecHandle.h"


class HalGpio
{
public:
    class Spec : public HalSpecHandle
    {
        public:
            using HalSpecHandle::HalSpecHandle;
    };

    HalGpio(Spec& spec);

    bool isReady();
    int pinConfigure(bool mode);
    int pinSet(bool set);
    int toggle();
    int read() const;

private:
    Spec& _spec;
};


#endif
