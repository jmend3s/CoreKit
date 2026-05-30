
#ifndef __RESULT_H__
#define __RESULT_H__

#include "Error.h"

#include <compare>


class Result
{
public:
    constexpr Result()
        : _error(Error::None)
    {}

    constexpr Result(Error const error)
        : _error(error)
    {}

    static constexpr Result success()
    {
        return { Error::None };
    }

    static constexpr Result fail(Error const error)
    {
        return { error };
    }

    constexpr bool isOk() const
    {
        return _error == Error::None;
    }

    constexpr bool isError() const
    {
        return _error != Error::None;
    }

    constexpr Error error() const
    {
        return _error;
    }

    auto operator<=>(const Result&) const = default;

private:
    Error _error;
};

#endif
