#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _func(const char *format, ...);
int _myputchar(char n);
int print_string(const char *str);
int print_char(int character);

#endif
