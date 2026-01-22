
#ifndef __HAL_GPIO_FAKE_H__
#define __HAL_GPIO_FAKE_H__


struct FakeGpioState
{
    bool ready = true;
    bool configured = false;
    bool outputMode = false;
    bool level = false;

    int setCalls = 0;
    int toggleCalls = 0;
};


#endif
