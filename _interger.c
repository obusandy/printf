#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
/**
 * _func - does formatted printing
 * @format: The field
 * Return: Nothing
*/
int _func(const char *format, ...)
{
	va_list args;
	char f;
	int i, j, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			f = format[i + 1];
			if (f == 'd' || f == 'i')
			{
				int num = va_arg(args, int);
				char digits[12];
				int num_digits = 0;

				if (num < 0)
				{
					putchar('-');
					num = -num;
					count++;
				}

				do
				{
					digits[num_digits++] = num % 10 + '0';
					num /= 10;
					} while (num > 0);

				for (j = num_digits - 1; j >= 0; j--)
				{
					putchar(digits[j]);
					count++;
				}

				i++;
			} else
            {
				putchar('%');
				putchar(f);
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
	return count;
}
