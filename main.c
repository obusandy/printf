#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int i;
	int count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		count = i + 1;
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char character = va_arg(args, int);

				putchar (character);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				printf("%s", str);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				putchar ('%');
				i++;
			}
		}
		else
		{
			putchar(format[i]);
		}
	}

	va_end(args);
	return (count);
}