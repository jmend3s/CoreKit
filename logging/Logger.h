
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "LogLevels.h"
#include "LogRecord.h"
#include "LogSerializer.h"


class Logger
{
public:
    static Logger& instance();

    template<typename... Args>
    bool push(LogLevel level, char const* module,
        char const* message, Args... args)
    {
        static_assert(sizeof...(args) <= MAX_LOG_ARGUMENTS, "Too many log arguments");

        LogRecord record {};
        record.level = level;
        record.module = module;
        record.message = message;
        record.argumentCount = sizeof...(args);
    }

private:
    Logger() = default;

    void serializeArguments()
    {}

    template<typename T, typename... Remaining>
    void serializeArguments(LogArgument* arguments, T value, Remaining... remaining)
    {
        LogSerializer serializer;
        arguments[0] = serializer.serialize(value);
        serializeArguments(arguments + 1, remaining...);
    }
};


#ifndef CK_LOG_MODULE
#define CK_LOG_MODULE "DEFAULT"
#endif

#define CK_LOG_INFO(message, ...) \
ck::Logger::instance().push( \
ck::LogLevel::Info, \
CK_LOG_MODULE, \
message, \
##__VA_ARGS__)

#define CK_LOG_ERROR(message, ...) \
ck::Logger::instance().push( \
ck::LogLevel::Error, \
CK_LOG_MODULE, \
message, \
##__VA_ARGS__)


#endif
