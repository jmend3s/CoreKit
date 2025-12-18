
#ifndef __ADC_SERVICE_H__
#define __ADC_SERVICE_H__

#include "Component.h"
#include "Adc.h"
#include "TimerService.h"

#include <map>
#include <functional>


class AdcService : public Component
{
public:
    enum class Rate { Ms1, Ms10, Ms20, Ms100 };

    AdcService(TimerService const& timer);

    void initialize() override;
    void update() override;

    void registerAdc(Adc* adc, Rate rate);

private:
    TimerService const& _timer;
    std::map<Adc*, Rate> _adcs;

    std::map<Rate, std::function<bool()>> const _rates
    {
        { Rate::Ms1, [this]() { return _timer.ms1(); } },
        { Rate::Ms10, [this]() { return _timer.ms10(); } },
        { Rate::Ms20, [this]() { return _timer.ms20(); } },
        { Rate::Ms100, [this]() { return _timer.ms100(); } }
    };
};


#endif