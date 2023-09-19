#include "main.h"
/**
 * _myputchar - write characters on stdout
 * @n: character
 * Return: 1
*/
int _myputchar(char n)
{
	return (write(1, &n, 1));
}
