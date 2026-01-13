
#ifndef __SCHEDULABLE_COMPONENT_H__
#define __SCHEDULABLE_COMPONENT_H__

#include "Component.h"

#include <stdint.h>


class SchedulableComponent : public Component
{
public:
    virtual uint32_t periodUs() const = 0;
};


#endif
