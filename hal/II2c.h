
#ifndef __I_I2C_H__
#define __I_I2C_H__

#include <cstdint>


class II2c
{
public:
    virtual bool isReady() = 0;
    virtual int write(const uint8_t* tx, uint16_t size) = 0;
    virtual int read(uint8_t* rx, uint16_t size) = 0;
    virtual int writeRead(const uint8_t* tx, uint16_t txSize, uint8_t* rx, uint16_t rxSize) = 0;

    virtual int writeReg(uint8_t reg, const uint8_t*  data, uint16_t size) = 0;
    virtual int readReg(uint8_t reg, uint8_t* data, uint16_t size) = 0;

    virtual ~II2c() = default;
};


#endif
