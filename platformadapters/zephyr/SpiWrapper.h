
#ifndef __SPI_WRAPPER_H__
#define __SPI_WRAPPER_H__

#include "HalSpecHandle.h"


class SpiWrapper
{
public:
    class SpecHandle : public HalSpecHandle
    {
    public:
        using HalSpecHandle::HalSpecHandle;
    };

    SpiWrapper(SpecHandle& spec);

    bool isReady();
    int transceive(uint8_t* tx, uint8_t* rx, uint16_t size);

private:
    SpecHandle _spec;
};


#endif
