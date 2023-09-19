#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

/**
 * print_char - Write the character to standard output
 * @character: The character to write
 * Return: The number of characters written (1 on success, -1 on failure)
 */
int print_char(int character)
{
	char c = character;

	if (write(STDOUT_FILENO, &c, 1) == -1)
	{
		perror("write");
		return (-1);
	}
	return (1);
}

/**
 * print_string - Write the string to standard output
 * @str: The string to write
 * Return: The number of characters written
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		int result = write(STDOUT_FILENO, str, 1);

		if (result == -1)
		{
			perror("write");
			return (-1);
		}
		count++;
		str++;
	}
	return (count);
}

/**
 * _printf - Custom printf
 * @format: Parsed in parameter
 * Return: The number of characters written
 */
int _printf(const char *format, ...)
{
	int i, count = 0, result;
	va_list args;
	char next_char;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char character = va_arg(args, int);

				i++;
				result = print_char(character);

				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);

				i++;
				result = print_string(str);

				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
			}
			else if (format[i + 1] == '%')
			{
				char percent = '%';
				int result = print_char(percent);

				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
				i++;
			}
			else
			{
				char percent = '%';
				int result = print_char(percent);

				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				next_char = format[i + 1];
				
				result = print_char(next_char);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
				i++;
			}
		}
		else
		{
			int result = print_char(format[i]);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
		}
	}
	va_end(args);
	return (count);
}
