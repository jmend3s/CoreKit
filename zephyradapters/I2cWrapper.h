
#ifndef __I2C_WRAPPER_H__
#define __I2C_WRAPPER_H__

#include "HalSpecHandle.h"


class I2cWrapper
{
public:
    class SpecHandle : public HalSpecHandle
    {
    public:
        using HalSpecHandle::HalSpecHandle;
    };

    I2cWrapper(SpecHandle& spec);

    bool isReady();
    // int write(uint8_t* tx, uint16_t size);
    // int read(uint8_t * rx, uint16_t size);
    int writeRead(uint8_t* tx,  uint16_t txSize, uint8_t* rx, uint16_t rxSize);

private:
    SpecHandle _spec;
};

#endif