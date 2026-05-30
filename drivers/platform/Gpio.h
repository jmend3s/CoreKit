
#ifndef __GPIO_H__
#define __GPIO_H__

#include "IGpio.h"
#include "GpioTypes.h"
#include "zephyr/GpioWrapper.h"


using GpioSpec = GpioWrapper::SpecHandle;
class Gpio : public IGpio
{
public:
    Gpio(GpioSpec& spec, GpioMode mode);

    Result configure() override;

    void set(GpioState state) override;
    void toggle() override;

    GpioState read() const override;

private:
    GpioMode _mode;
    GpioState _state;

    GpioWrapper _gpio;
};


#endif
