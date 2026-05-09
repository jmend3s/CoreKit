
#include "LogRingBuffer.h"


bool LogRingBuffer::push(LogRecord const& record)
{
    bool pushable = false;
    if (!isFull())
    {
        _records[_head] = record;
        _head = (_head + 1) % CAPACITY;
        ++_size;
        pushable = true;
    }

    return pushable;
}

bool LogRingBuffer::pop(LogRecord& record)
{
    bool popable = false;
    if (!isEmpty())
    {
        record = _records[_tail];
        _tail = (_tail + 1) % CAPACITY;
        --_size;
        popable = true;
    }

    return popable;
}

bool LogRingBuffer::isFull() const
{
    return _size == CAPACITY;
}

bool LogRingBuffer::isEmpty() const
{
    return _size == 0;
}
