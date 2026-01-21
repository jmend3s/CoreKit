
#include "HalGpio.h"

#include <zephyr/drivers/gpio.h>


static gpio_dt_spec const* toDt(HalGpio::Spec& spec)
{
    return reinterpret_cast<gpio_dt_spec const*>(spec.spec());
}

HalGpio::HalGpio(Spec& spec)
    : _spec(spec)
{
}

bool HalGpio::isReady()
{
    return device_is_ready(toDt(_spec)->port);
}

int HalGpio::pinConfigure(bool mode)
{
    auto const flags = mode ? GPIO_INPUT : GPIO_OUTPUT;
    return gpio_pin_configure_dt(toDt(_spec), flags);
}

int HalGpio::pinSet(bool set)
{
    return gpio_pin_set_dt(toDt(_spec), set);
}

int HalGpio::toggle()
{
    return gpio_pin_toggle_dt(toDt(_spec));
}

int HalGpio::read() const
{
    return gpio_pin_get_dt(toDt(_spec));
}
