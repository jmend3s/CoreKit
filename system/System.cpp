
#include "System.h"
#include "SystemClock.h"
#include "SystemTime.h"


System::System(Component** components, uint64_t* tickStorage, size_t const count,
    ISystemTime& time, uint32_t const tickPeriodUs)
    :  _time(time)
    ,  _scheduler(components, tickStorage, count, _tickCounter)
    , _tickPeriodUs(tickPeriodUs)
{
}

void System::initialize()
{
    SystemClock::bind(&_tickCounter);
    _scheduler.initialize();
}

void System:: run()
{
    initialize();

    _nextTickUs = _time.now();
    while (true)
    {
        runOnce();
        pace();
    }
}

void System::runOnce()
{
    _tickCounter.advance();
    _scheduler.runOnce();
}

void System::pace()
{
    _nextTickUs += _tickPeriodUs;
    if (_time.now() < _nextTickUs)
    {
        _time.sleep(static_cast<uint32_t>(_nextTickUs - _time.now()));
    }
}
