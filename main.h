#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

void _putchar(char n)
{
    write(1, &n, 1);
}
int _printf(const char *format, ...);

#endif
