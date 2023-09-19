#include "main.h"
/**
 * _myputchar - write characters on stdout
 * @n: character
 * Return: Nothing
*/
int _myputchar(char n)
{
	write(1, &n, 1);
}
