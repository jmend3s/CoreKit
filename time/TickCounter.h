
#ifndef __TICK_COUNTER_H__
#define __TICK_COUNTER_H__

#include <cstdint>

class TickCounter
{
public:
    void reset();
    void advance();
    uint32_t now() const;

private:
    uint32_t _tick = 0;
};


#endif
