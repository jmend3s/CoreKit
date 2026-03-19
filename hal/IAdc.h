
#ifndef __I_ADC_H__
#define __I_ADC_H__

#include <cstdint>


class IAdc
{
public:
    virtual void initialize() = 0;
    virtual void read() = 0;
    virtual int32_t lastReading() const = 0;
    virtual ~IAdc() = default;
};


#endif
