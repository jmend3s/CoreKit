
#include "Application.h"

#include <zephyr/kernel.h>


Application::Application(Component** components, size_t const count)
    : _components(components)
    , _count(count)
{
}

void Application::initialize() const
{
    for (size_t i = 0; i < _count; i++)
    {
        _components[i]->initialize();
    }
}

void Application::update() const
{
    for (size_t i = 0; i < _count; i++)
    {
        _components[i]->update();
    }
}

void Application::run()
{
    initialize();

    while (true)
    {
        update();
    }
}

void Application::loopSleep()
{
    k_msleep(1);
}
