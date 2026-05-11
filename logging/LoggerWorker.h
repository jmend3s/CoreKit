
#ifndef __LOGGER_WORKER_H__
#define __LOGGER_WORKER_H__

#include "IPrinter.h"


class LoggerWorker
{
public:
    explicit LoggerWorker(IPrinter& printer);

    void work();

private:
    static constexpr uint32_t BUFFER_SIZE = 256;

    IPrinter& _printer;
    char _buffer[BUFFER_SIZE];
};

#endif
