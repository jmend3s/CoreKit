
#include "LoggerWorker.h"

#include "LogFormater.h"
#include "Logger.h"


LoggerWorker::LoggerWorker(IPrinter& printer)
    : _printer(printer)
{
}

void LoggerWorker::work()
{
    LogRecord record {};
    while (Logger::instance().pop(record))
    {
        int const length = static_cast<int>(LogFormater::format(record, _buffer, BUFFER_SIZE));
        _printer.write(_buffer, length);
    }
}
