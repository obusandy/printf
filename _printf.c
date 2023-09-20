#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _print_string - Handle %s format specifier
 * @args: va_list containing the argument
 * @count: Pointer to the count variable
 */
void _print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		*count += _myputchar(*str);
		str++;
	}
}
/**
* _printf - Custom printf
* @format: format string
* Return: count
*/
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (-1);
	}
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
			_print_string(args, &count);
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
