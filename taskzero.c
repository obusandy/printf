#include "main.h"

/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int i;
	int count = 0;
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

				_putchar (character);
				i++;
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				i++;
				count += printf("%s", str);
			}
			else if (format[i + 1] == '%')
			{
				_putchar ('%');
				count++;
			}
		} else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
