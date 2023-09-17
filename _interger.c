#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - does formatted printing
 * @format: The field
 * Return: Nothing
*/
int _printf(const char *format, ...)
{
        va_list args;
        char f;
        int i;

        va_start(args, format);
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        f = format[i + 1];
                        if (f == 'd'  || f == 'i')
                        {
                                int num = va_arg(args, int);

                                printf("%d", num);
                                i++;
                        }
                        else
                        {
                                putchar('%');
                                putchar(format[i + 1]);
                                i++;
                        }
                } else
                {
                        putchar(format[i]);
                }
        }
        va_end(args);
}
