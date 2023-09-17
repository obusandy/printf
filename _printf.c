#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char character;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				character = va_arg(args, int);

				putchar (character);
				i++;
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				for (j = 0; str[j] != '\0'; j++)
				{
					putchar(str[j]);
					count++;
				}
					i++;
			}
			else if (format[i + 1] == '%')
			{
				putchar ('%');
				count++;
			} else
			{
				va_end(args);
				return (-1);
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
