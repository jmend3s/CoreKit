
#include "Scheduler.h"

#include "SystemClock.h"


Scheduler::Scheduler(Component** components, uint64_t* lastTickStorage,
    size_t const count, TickCounter& tickCounter
)
    : _components(components)
    , _lastTick(lastTickStorage)
    , _count(count)
    , _tickCounter(tickCounter)
{
}

void Scheduler::initialize()
{
    uint64_t const now = _tickCounter.now();
    for (size_t i = 0; i < _count; i++)
    {
        _components[i]->initialize();
        _lastTick[i] = now;
    }
}

void Scheduler::runOnce()
{
    uint64_t const currentTick = _tickCounter.now();
    for (size_t i = 0; i < _count; i++)
    {
        uint64_t const elapsed = currentTick - _lastTick[i];
        if (elapsed >= _components[i]->period())
        {
            _components[i]->update();
            _lastTick[i] = currentTick;
        }
    }
}
