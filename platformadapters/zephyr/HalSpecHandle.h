
#ifndef __HAL_SPEC_HANDLE_H__
#define __HAL_SPEC_HANDLE_H__

#include <cstdint>


class HalSpecHandle
{
public:
    constexpr HalSpecHandle(uintptr_t const spec) : _spec(spec)
    {
    }

    uintptr_t spec()
    {
        return _spec;
    }

private:
    uintptr_t _spec;
};


#endif
