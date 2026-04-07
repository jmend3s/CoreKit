
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
    int write(const uint8_t* tx, uint16_t size) override;
    int read(uint8_t* rx, uint16_t size) override;
    int writeRead(const uint8_t* tx, uint16_t txSize, uint8_t* rx, uint16_t rxSize) override;

    int writeReg(uint8_t reg, const uint8_t* data, uint16_t size) override;
    int readReg(uint8_t reg, uint8_t* data, uint16_t size) override;

private:
    I2cWrapper _i2c;
};

#endif