#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf
 * @format: format string
 * Return: count
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _myputchar(format[i]);
		} else if (format[i + 1] == 'c')
		{
			count += _myputchar(va_arg(args, int));
			i++;
		} else if (format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);

			if (str == NULL)
			{
				str = "(null)";
			}
			while (*str)
			{
				count += _myputchar(*str);
				str++;
			}
			i++;
		} else if (format[i + 1] == '%')
		{
			_myputchar('%');
			count++;
			i++;
		} else
		{
			count += _myputchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}
