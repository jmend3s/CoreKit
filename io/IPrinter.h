
#ifndef __I_PRINTER_H__
#define __I_PRINTER_H__


class IPrinter
{
public:
    virtual void write(const char* data, int length) = 0;
    virtual ~IPrinter() = default;
};


#endif
