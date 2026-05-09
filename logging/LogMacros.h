
#ifndef __LOG_MACROS_H__
#define __LOG_MACROS_H__

#include "Logger.h"
#include "LogLevels.h"


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
