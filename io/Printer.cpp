
#include "Printer.h"

#include <zephyr/kernel.h>


void Printer::write(char const* data, int const length)
{
    printk("%.*s", length, data);
}
