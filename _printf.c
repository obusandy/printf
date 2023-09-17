#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - write characters on stdout
 * @n: character
 * Return: Nothing
*/
void _putchar(char n)
{
	write(1, &n, 1);
}
/**
 * print_percent - Prints % sign
 * Return: Always 1 for success
*/
int print_percent(void)
{
	_putchar('%');
	return (1);
}
/**
 * print_char - Print the character
 * @character: Takes the character
 * Return: Always 1
*/
int print_char(int character)
{
	_putchar(character);
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
		_putchar(*str);
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

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char character = va_arg(args, int);

				i++;
				count += print_char(character);
			} else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				i++;
				count += print_string(str);
			} else if (format[i + 1] == '%')
			{
				_putchar ('%');
				count++;
				i++;
			} else
			{
				_putchar('%');
				_putchar(format[i + 1]);
				i++;
				count += 2;
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
