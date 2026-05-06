
#include "Printer.h"

#include <zephyr/kernel.h>

#include <cstdarg>


void Printer::print(char const* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintk(fmt, args);
    va_end(args);
}
