#include "main.h"
/**
 * _myputchar - write characters on stdout
 * @n: character
 * Return: Nothing
*/
void _myputchar(char n)
{
	write(1, &n, 1);
}
