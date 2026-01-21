
#ifndef __GPIO_H__
#define __GPIO_H__

#include "Component.h"
#include "HalGpio.h"

// Should this be a component?
// Should this inherit from HalGpio or contain it like so?
// Should this be a Component if it does not update?
using GpioSpec = HalGpio::Spec;
class Gpio : public Component
{
public:
    enum class Mode { Input, Output };
    enum class State { Low, High };

    Gpio(GpioSpec& spec, Mode mode);

    void initialize() override;
    void update() override;

    void set(State state);
    void toggle();

    State read() const;

private:
    Mode _mode;
    State _state;

    HalGpio _hal;
};


#endif
