
#ifndef __TIMER_SERVICE_H__
#define __TIMER_SERVICE_H__

#include "SchedulableComponent.h"
#include "TickCounter.h"
#include "Timer.h"


class TimerService : public SchedulableComponent
{
public:
    TimerService();

    void initialize() override;
    void update() override;
    uint32_t periodTick() const override;

    bool ms1() const;
    bool ms10() const;
    bool ms20() const;
    bool ms100() const;
    bool ms1000() const;

private:
    Timer _1ms;
    Timer _10ms;
    Timer _20ms;
    Timer _100ms;
    Timer _1000ms;
};


#endif
