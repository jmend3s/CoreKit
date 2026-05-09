
#ifndef __I_PRINTER_H__
#define __I_PRINTER_H__

#include <cstdint>


class IPrinter
{
public:
    virtual void write(const char* data, uint32_t length) = 0;
};

#endif
