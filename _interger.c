#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _func - does formatted printing
 * @format: The field
 * Return: Nothing
*/
int _func(const char *format, ...)
{
	va_list args;
	char f;
	int i, count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);

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
				count++;
			}
			else
			{
				putchar('%');
				putchar(format[i + 1]);
				i++;
				count++;
			}
		} else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
