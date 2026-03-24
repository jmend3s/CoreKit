
#ifndef __I_I2C_H__
#define __I_I2C_H__

#include <cstdint>


class II2c
{
public:
    virtual bool isReady() = 0;
    virtual int write(uint8_t* tx, uint8_t size) = 0;
    virtual int read(uint8_t* rx, uint8_t size) = 0;
    virtual int writeRead(uint8_t* tx, uint8_t txSize, uint8_t* rx, uint8_t rxSize) = 0;

    virtual ~II2c() = default;
};


#endif
