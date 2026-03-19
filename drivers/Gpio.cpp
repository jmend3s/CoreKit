
#include "Gpio.h"


Gpio::Gpio(GpioSpec& spec, GpioMode const mode)
    : _mode(mode)
    , _state(GpioState::Low)
    , _gpio(spec)
{
}

bool Gpio::configure()
{
    bool configured = false;
    if (_gpio.isReady())
    {
        _gpio.pinConfigure(_mode == GpioMode::Output);
        configured = true;
    }
    return configured;
}

void Gpio::set(GpioState const state)
{
    if (_mode == GpioMode::Output)
    {
        _state = state;
        _gpio.pinSet(state == GpioState::Low);
    }
}

void Gpio::toggle()
{
    if (_mode == GpioMode::Output)
    {
        _gpio.toggle();
        _state = _state == GpioState::Low ? GpioState::High : GpioState::Low;
    }
}

GpioState Gpio::read() const
{
    return _gpio.read() ? GpioState::High : GpioState::Low;
}
