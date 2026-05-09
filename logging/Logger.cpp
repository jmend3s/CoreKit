
#include "Logger.h"


Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

bool Logger::pop(LogRecord& record)
{
    return _ringBuffer.pop(record);
}
