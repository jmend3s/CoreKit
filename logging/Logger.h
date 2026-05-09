#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "LogLevels.h"
#include "LogRecord.h"
#include "LogSerializer.h"


class Logger
{
public:
    static Logger& instance();

    template<class... Args>
    bool push(LogLevel level, char const* module,
        char const* message, Args const&... args)
    {
        static_assert(sizeof...(args) <= MAX_LOG_ARGUMENTS, "Too many log arguments");

        LogRecord record {};
        record.level = level;
        record.module = module;
        record.message = message;
        record.argumentCount = sizeof...(Args);

        serializeArguments(record.arguments, args...);

        return true;
    }

private:
    Logger() = default;

    void serializeArguments(LogArgument*)
    {}

    template<class T, class... Remaining>
    void serializeArguments(LogArgument* arguments, T const& value, Remaining const&... remaining)
    {
        serializeArgument(arguments, value);
        serializeArguments(arguments + 1, remaining...);
    }

    template<class T>
    static void serializeArgument(LogArgument* arguments, T const& value)
    {
        arguments[0] = LogSerializer<T>::serialize(value);
    }
};


#ifndef CK_LOG_MODULE
#define CK_LOG_MODULE "DEFAULT"
#endif

#define CK_LOG_INFO(message, ...) \
Logger::instance().push( \
LogLevel::Info, \
CK_LOG_MODULE, \
message, \
##__VA_ARGS__)

#define CK_LOG_ERROR(message, ...) \
Logger::instance().push( \
LogLevel::Error, \
CK_LOG_MODULE, \
message, \
##__VA_ARGS__)


#endif
