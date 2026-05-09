
#ifndef __SYSTEM_PRINT_H__
#define __SYSTEM_PRINT_H__

#include "IPrinter.h"


class Printer : public IPrinter
{
public:
    void write(const char* data, int length) override;
};


#endif
