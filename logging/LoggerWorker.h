
#ifndef __LOGGER_WORKER_H__
#define __LOGGER_WORKER_H__

#include "IPrinter.h"

#include <cstdio>


class LoggerWorker
{
public:
    explicit LoggerWorker(IPrinter& printer);

    void work();

private:
    static constexpr size_t _bufferSize = 256;

    IPrinter& _printer;
    char _buffer[_bufferSize]{};
};

#endif
