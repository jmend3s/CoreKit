
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <cstdint>


class Component
{
public:
    virtual ~Component() = default;

    virtual void initialize() = 0;
    virtual void update() = 0;
    virtual uint32_t period() const = 0;
};


#endif
