
#ifndef __TIMER_SERVICE_H__
#define __TIMER_SERVICE_H__

#include "SchedulableComponent.h"
#include "TickCounter.h"
#include "TimerTick.h"

class TimerService : public SchedulableComponent
{
public:
    TimerService(TickCounter& _tickCounter);

    void initialize() override;
    void update() override;
    uint32_t periodTick() const override;

    bool ms1() const;
    bool ms10() const;
    bool ms20() const;
    bool ms100() const;
    bool ms1000() const;

private:
    TickCounter& _tickCounter;

    TimerTick _1ms;
    TimerTick _10ms;
    TimerTick _20ms;
    TimerTick _100ms;
    TimerTick _1000ms;
};

#endif