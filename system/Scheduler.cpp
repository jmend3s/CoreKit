
#include "Scheduler.h"
#include "SystemClock.h"


Scheduler::Scheduler(SchedulableComponent** components, uint64_t* lastTickStorage,
    size_t count, TickCounter& tickCounter
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
    uint64_t currentTick = _tickCounter.now();

    for (size_t i = 0; i < _count; i++)
    {
        uint64_t elapsed = currentTick - _lastTick[i];
        if (elapsed >= _components[i]->periodTicks())
        {
            _components[i]->update();
            _lastTick[i] = currentTick;
        }
    }
}
