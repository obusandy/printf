#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - Print the character
 * @character: Takes the character
 * Return: Always 1
*/
int print_char(int character)
{
	putchar(character);
	return (1);
}
/**
 * print_string - Simplify the work
 * @str: This is the pointer
 * Return: The count always 0
*/
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}
/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				int num = va_arg(args, int);

				i++;
				count += print_char(character);
			} else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				i++;
				count += print_string(str);
			} else if (format[i + 1] == '%')
			{
				putchar ('%');
				count++;
				i++;
			} else
			{
				putchar('%');
				putchar(format[i + 1]);
				i++;
				count += 2;
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
