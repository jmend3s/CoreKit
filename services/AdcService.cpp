
#include "AdcService.h"

AdcService::AdcService(TimerService const& timer)
    : _timer(timer)
{
}

void AdcService::initialize()
{
    for (auto const& adc : _adcs)
    {
        adc.first->initialize();
    }
}

void AdcService::update()
{
    for (auto const& [adc, rate] : _adcs)
    {
        if (_rates.at(rate))
        {
            adc->update();
        }
    }
}

void AdcService::registerAdc(Adc* adc, Rate rate)
{
    _adcs.emplace(adc, rate);
}
