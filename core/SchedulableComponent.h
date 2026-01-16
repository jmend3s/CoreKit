
#ifndef __SCHEDULABLE_COMPONENT_H__
#define __SCHEDULABLE_COMPONENT_H__

#include "Component.h"

#include <cstdint>


class SchedulableComponent : public Component
{
public:
    virtual uint32_t periodTick() const = 0;
};


#endif
