
#ifndef __TIMER_SERVICE_H__
#define __TIMER_SERVICE_H__

#include "Timer.h"
#include "SchedulableComponent.h"
#include "TickCounter.h"


class TimerService : public SchedulableComponent
{
public:
    TimerService(TickCounter& _tickCounter);

    void initialize() override;
    void update() override;
    uint32_t periodTicks() const override;

    bool ms1() const;
    bool ms10() const;
    bool ms20() const;
    bool ms100() const;

private:
    TickCounter& _tickCounter;

    Timer _1ms;
    Timer _10ms;
    Timer _20ms;
    Timer _100ms;
};

#endif