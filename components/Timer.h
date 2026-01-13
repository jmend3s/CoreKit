
#ifndef __TIMER_H__
#define __TIMER_H__

#include <cstdint>


class Timer
{
public:
    Timer(uint32_t periodTicks);

    void reset(uint32_t currentTick);
    void update(uint32_t currentTick);

    bool elapsed() const;

private:
    uint32_t _periodTicks;
    uint64_t _lastTick;
    bool _elapsed;
};

#endif