#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _myputchar - Prints a character
 * @c: Input pointer
 * Return: 1
*/
int _myputchar(char c)
{
	return (write(1, &c, 1));
}
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
		}
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_myputchar(va_arg(args, int));
			i++;
			count++;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);

			while (*str)
			{
				_myputchar(*str);
				count++;
				str++;
			}
			i++;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			_myputchar('%');
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
