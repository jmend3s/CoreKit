
#ifndef __IGPIO_H__
#define __IGPIO_H__

#include "GpioTypes.h"


class IGpio
{
public:
    virtual bool configure() = 0;
    virtual void set(GpioState state) = 0;
    virtual void toggle() = 0;
    virtual GpioState read() const = 0;
    virtual ~IGpio() = default;
};


#endif
