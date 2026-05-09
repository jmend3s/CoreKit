
#ifndef __LOG_RING_BUFFER_H__
#define __LOG_RING_BUFFER_H__

#include "LogRecord.h"


class LogRingBuffer
{
public:
    bool push(LogRecord const& record);
    bool pop(LogRecord& record);
    bool isFull() const;
    bool isEmpty() const;

    static constexpr uint32_t CAPACITY = 64;

private:
    LogRecord _records[CAPACITY];

    uint32_t _head;
    uint32_t _tail;
    uint32_t _size;
};


#endif
