
#include "System.h"
#include "SystemClock.h"
#include "SystemTime.h"


System::System(SchedulableComponent** components, uint64_t* tickStorage, size_t const count, ISystemTime& time)
    :  _time(time)
    ,  _scheduler(components, tickStorage, count, _tickCounter)
{
}

void System::initialize()
{
    SystemClock::bind(&_tickCounter);
    _scheduler.initialize();
}

void System::run()
{
    initialize();

    uint64_t nextTickUs = _time.now();
    while (true)
    {
        _scheduler.runOnce();

        nextTickUs += _tickPeriodUs;
        if (_time.now() < nextTickUs)
        {
            _time.sleep(static_cast<uint32_t>(nextTickUs - _time.now()));
        }

        _tickCounter.advance();
    }
}
