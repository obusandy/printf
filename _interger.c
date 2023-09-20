#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _func - does formatted printing
 * @interger: The field
 * Return: Nothing
*/
int _func(const char *interger, ...)
{
	va_list args;
	char f, digits[12];
	int i, j, count = 0, num_digits = 0;

	va_start(args, interger);
	for (i = 0; interger[i] != '\0'; i++)
	{
		if (interger[i] == '%')
		{
			f = interger[i + 1];
			if (f == 'd' || f == 'i')
			{
				int num = va_arg(args, int);

				if (num < 0)
				{
					_myputchar('-');
					num = -num;
					count++;
				} do {
					digits[num_digits++] = num % 10 + '0';
					num /= 10;
					} while (num > 0); for (j = num_digits - 1; j >= 0; j--)
				{
					_myputchar(digits[j]);
					count++;
				}
				i++;
			} else
			{
				_myputchar('%');
				_myputchar(f);
				i++;
				count++;
			}
		} else
		{
			_myputchar(interger[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}
