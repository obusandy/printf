#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;

                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    count += putchar('%');
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}