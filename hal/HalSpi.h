
#ifndef __HAL_SPI_H__
#define __HAL_SPI_H__

#include "HalSpecHandle.h"


class HalSpi
{
public:
    class Spec : public HalSpecHandle
    {
    public:
        using HalSpecHandle::HalSpecHandle;
    };

    HalSpi(Spec& spec);

    bool isReady();
    int transceive(uint8_t* tx, uint8_t* rx, uint16_t size);

private:
    Spec _spec;
};


#endif
