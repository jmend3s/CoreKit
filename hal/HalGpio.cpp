
#include "HalGpio.h"

#include <zephyr/drivers/gpio.h>


HalGpio::HalGpio(Spec& spec)
    : _spec(spec)
{
}

bool HalGpio::isReady()
{
    return device_is_ready(static_cast<gpio_dt_spec const*>(_spec.dt)->port);
}

int HalGpio::pinConfigure(bool mode)
{
    auto const flags = mode ? GPIO_INPUT : GPIO_OUTPUT;
    return gpio_pin_configure_dt(static_cast<gpio_dt_spec const*>(_spec.dt), flags);
}

int HalGpio::pinSet(bool set)
{
    return gpio_pin_set_dt(static_cast<gpio_dt_spec const*>(_spec.dt), set);
}

int HalGpio::toggle()
{
    return gpio_pin_toggle_dt(static_cast<const gpio_dt_spec*>(_spec.dt));
}

int HalGpio::read() const
{
    return gpio_pin_get_dt(static_cast<gpio_dt_spec const*>(_spec.dt));
}
