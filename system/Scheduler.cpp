
#include "Scheduler.h"
#include "SystemClock.h"


Scheduler::Scheduler(SchedulableComponent** components, size_t count)
    : _components(components)
    , _count(count)
{
    _lastRun = static_cast<uint64_t*>(std::calloc(count, sizeof(uint64_t)));
}

void Scheduler::initialize() const
{
    for (size_t i = 0; i < _count; i++)
    {
        _components[i]->initialize();
        _lastRun[i] = SystemClock::nowUs();
    }
}

void Scheduler::runOnce() const
{
    uint64_t const now = SystemClock::nowUs();

    for (size_t i = 0; i < _count; i++)
    {
        auto* component = _components[i];
        uint64_t elapsed = SystemClock::nowUs() - _lastRun[i];

        if (elapsed >= component->periodUs())
        {
            component->update();
            _lastRun[i] = now;
        }
    }
}
