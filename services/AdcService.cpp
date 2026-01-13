
#include "AdcService.h"

AdcService::AdcService(AdcEntry* entries, size_t const size, TimerService const& timer)
    : _adcs(entries)
    , _size(size)
    , _timer(timer)
{
}

void AdcService::initialize()
{
    for (size_t i = 0; i < _size; i++)
    {
        _adcs[i].adc->initialize();
    }
}

void AdcService::update()
{
    for (size_t i = 0; i < _size; i++)
    {
        if (isDue(_adcs[i].rate))
        {
            _adcs[i].adc->update();
        }
    }
}

bool AdcService::isDue(Rate const rate) const
{
    switch (rate)
    {
        case Rate::Ms1: return _timer.ms1();
        case Rate::Ms10: return _timer.ms10();
        case Rate::Ms20: return _timer.ms20();
        case Rate::Ms100: return _timer.ms100();
    }
}
