
#ifndef __TIMER_MS_H__
#define __TIMER_MS_H__

#include "Component.h"

#include <cstdint>


class TimerMs : public Component
{
public:
    TimerMs(uint32_t periodMs);

    void initialize() override;
    void update() override;

    bool elapsed() const;
    uint32_t period() const;

private:
    uint32_t _periodMs;
    uint64_t _lastTick;
    bool _elapsed;
};


#endif
