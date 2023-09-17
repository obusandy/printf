#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - does formatted printing
 * @format: The field
 * return: Nothing
*/
int _printf(const char *format, ...)
{
	int count = 0;
	char f;
	int i;

	va_list args;

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
			}
			else
			{
				putchar('%');
				putchar(f);
				count += 2;
				i++;
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
