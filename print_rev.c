#include "main.h"
/**
 * print_rev - prints a string in reverse
 * @s: a pointer to the string
 * @len: integer pointer
 * Return: Nothing
 */
void print_rev(char *s, int *len)
{
	if (!(*s))
		;
	else
	{
		print_rev(s + 1, len);
		printc(*s, len);
	}
}
