
#include "Application.h"
#include "SystemSleep.h"

#include <zephyr/kernel.h>


Application::Application(SchedulableComponent** components, size_t count)
    : _scheduler(components, count)
{
}

void Application::run()
{
    _scheduler.initialize();

    while (true)
    {
        _scheduler.runOnce();
        SystemSleep::sleepUs(100);
    }
}
