#include "main.h"
/**
 * _putchar - write characters on stdout
 * @n: character
 * Return: Nothing
*/
int _putchar(char n)
{
	return (write(1, &n, 1));
}
