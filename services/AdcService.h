
#ifndef __ADC_SERVICE_H__
#define __ADC_SERVICE_H__

#include "Component.h"
#include "TimerService.h"
#include "Adc.h"

#include <cstddef>


class AdcService : public Component
{
public:
    enum class Rate { Ms1, Ms10, Ms20, Ms100 };

    struct AdcEntry
    {
        Adc* adc;
        Rate rate;
    };

    AdcService(AdcEntry* entries, size_t size, TimerService const& timer);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

private:
    bool isDue(Rate rate) const;

    AdcEntry* _adcs;
    size_t _size;

    TimerService const& _timer;
};


#endif