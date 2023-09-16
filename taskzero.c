#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: the number of characters printed (excluding the null terminator)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char character = va_arg(args, int);
				putchar(character);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
			count++;
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count - 1); /* Exclude the null terminator */
}


/**
 * main - program entry point
 * Return: Always 0 success
*/
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");

	return (0);
}