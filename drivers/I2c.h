
#ifndef __I2C_H__
#define __I2C_H__

#include "II2c.h"
#include "I2cWrapper.h"


using I2cSpec = I2cWrapper::SpecHandle;
class I2c : public II2c
{
public:
    I2c(I2cSpec& spec);

    bool isReady() override;
    int write(uint8_t* tx, uint8_t size) override;
    int read(uint8_t* rx, uint8_t size) override;
    int writeRead(uint8_t* tx, uint8_t txSize, uint8_t* rx, uint8_t rxSize) override;

private:
    I2cWrapper _i2c;
};

#endif