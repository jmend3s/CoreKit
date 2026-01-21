
#include "Gpio.h"


Gpio::Gpio(GpioSpec& spec, Mode const mode)
    : _mode(mode)
    , _state(State::Low)
    , _hal(spec)
{
}

bool Gpio::configure()
{
    bool configured = false;
    if (_hal.isReady())
    {
        _hal.pinConfigure(_mode == Mode::Input);
        configured = true;
    }
    return configured;
}

void Gpio::set(State const state)
{
    if (_mode == Mode::Output)
    {
        _state = state;
        _hal.pinSet(state == State::High);
    }
}

void Gpio::toggle()
{
    if (_mode == Mode::Output)
    {
        _hal.toggle();
        _state = _state == State::Low ? State::High : State::Low;
    }
}

Gpio::State Gpio::read() const
{
    return _hal.read() ? State::High : State::Low;
}
