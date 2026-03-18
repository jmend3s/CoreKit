
#ifndef __GPIO_H__
#define __GPIO_H__

#include "zephyr/GpioWrapper.h"


using GpioSpec = GpioWrapper::SpecHandle;
class Gpio
{
public:
    enum class Mode { Input, Output };
    enum class State { Low, High };

    Gpio(GpioSpec& spec, Mode mode);

    bool configure();

    void set(State state);
    void toggle();

    State read() const;

private:
    Mode _mode;
    State _state;

    GpioWrapper _hal;
};


#endif
