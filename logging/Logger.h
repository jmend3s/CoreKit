
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "LogLevels.h"
#include "LogRecord.h"
#include "LogRingBuffer.h"
#include "LogSerializer.h"

#include "serializers/FloatSerializer.h"
#include "serializers/Int32Serializer.h"
#include "serializers/UInt32Serializer.h"
#include "serializers/StringSerializer.h"
#include "serializers/PointerSerializer.h"


class Logger
{
public:
    static Logger& instance();

    template<class... Args>
    bool push(LogLevel level, char const* module, char const* message, Args const&... args)
    {
        static_assert(sizeof...(Args) <= MAX_LOG_ARGUMENTS, "Too many log arguments");

        LogRecord record {};
        record.timestamp = 0;
        record.level = level;
        record.module = module;
        record.message = message;
        record.argumentCount = sizeof...(Args);

        uint32_t index = 0;
        ((record.arguments[index++] = LogSerializer<Args>::serialize(args)), ...);  // Investigate if the index is necessary

        return _ringBuffer.push(record);
    }

    bool pop(LogRecord& record);

private:
    Logger() = default;

    LogRingBuffer _ringBuffer;
};


#endif
