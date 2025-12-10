
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Component.h"

#include <cstdlib>


class Application
{
public:
    Application(Component** components, size_t count);
    virtual ~Application() = default;

    void initialize() const;
    void update() const;

    virtual void run();
    virtual void loopSleep();

protected:
    Component** _components;
    size_t _count;
};


#endif
