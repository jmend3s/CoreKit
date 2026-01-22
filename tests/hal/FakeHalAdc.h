
#ifndef __FAKE_HAL_ADC_H__
#define __FAKE_HAL_ADC_H__


struct FakeAdcState
{
    bool ready = true;

    bool channelSet = false;
    bool sequenceInitialized = false;
    bool readCalled = false;

    int32_t readValue = 0xAA;
};


#endif
