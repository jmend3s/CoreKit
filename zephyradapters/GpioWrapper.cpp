
#include "GpioWrapper.h"

#include <zephyr/drivers/gpio.h>


static gpio_dt_spec const* toDt(GpioWrapper::SpecHandle& spec)
{
    return reinterpret_cast<gpio_dt_spec const*>(spec.spec());
}

GpioWrapper::GpioWrapper(SpecHandle& spec)
    : _spec(spec)
{
}

bool GpioWrapper::isReady()
{
    return device_is_ready(toDt(_spec)->port);
}

int GpioWrapper::pinConfigure(bool mode)
{
    auto const flags = mode ? GPIO_OUTPUT : GPIO_INPUT;
    return gpio_pin_configure_dt(toDt(_spec), flags);
}

int GpioWrapper::pinSet(bool set)
{
    return gpio_pin_set_dt(toDt(_spec), set);
}

int GpioWrapper::toggle()
{
    return gpio_pin_toggle_dt(toDt(_spec));
}

int GpioWrapper::read() const
{
    return gpio_pin_get_dt(toDt(_spec));
}
