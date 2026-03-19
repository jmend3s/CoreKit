
#ifndef __GPIO_H__
#define __GPIO_H__

#include "IGpio.h"
#include "GpioTypes.h"
#include "GpioWrapper.h"


using GpioSpec = GpioWrapper::SpecHandle;
class Gpio : public IGpio
{
public:
    Gpio(GpioSpec& spec, GpioMode mode);

    bool configure();

    void set(GpioState state);
    void toggle();

    GpioState read() const;

private:
    GpioMode _mode;
    GpioState _state;

    GpioWrapper _gpio;
};


#endif
