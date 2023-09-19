#include "main.h"
#include <stdio.h>
#include <stdarg.h>
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
			_myputchar(format[i]);
			count++;
		} else if (format[i] == '%' && format[i + 1] == 'c')
		{
			_myputchar(va_arg(args, int));
			i++;
			count++;
		} else if (format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);

			while (*str)
			{
				count += _myputchar(*str);
				str++;
			}
			i++;
		} else if (format[i] == '%' && format[i + 1] == '%')
		{
			_myputchar('%');
			count++;
			i++;
		} else
		{
			_myputchar(format[i]);
			count++;
			return (-1);
		}
	}
	va_end(args);
	return (count);
}
