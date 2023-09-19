#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * print_positive - Print a positive integer
 * @num: The positive integer to print
 * Return: The number of characters printed
 */
int print_positive(int num)
{
	char digits[12];
	int count = 0, num_digits = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	while (num > 0)
	{
		digits[num_digits++] = num % 10 + '0';
		num /= 10;
	}

	for (int i = num_digits - 1; i >= 0; i--)
	{
		putchar(digits[i]);
		count++;
	}

	return (count);
}

/**
 * _func - Does formatted printing with support for negative integers
 * @format: The format string
 * Return: The number of characters printed
 */
int _func(const char *format, ...)
{
	va_list args;
	char f;
	int count = 0;

	va_start(args, format);
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			f = format[i + 1];
			if (f == 'd' || f == 'i')
			{
				int num = va_arg(args, int);

				if (num < 0)
				{
					putchar('-');
					count++;
					num = -num;
				}
				count += print_positive(num);
				i++;
			}
			else
			{
				putchar('%');
				putchar(f);
				count += 2;
				i++;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		}
	va_end(args);
	return (count);
}