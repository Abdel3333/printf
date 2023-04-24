#include "main.h"
/**
 * print_number - prints an integer
 * @n: the integer to print
 * @len: the pointer to int
 * Return: Nothing
 */
void print_number(int n, int *len)
{
	if (n < 0)
	{
		printc('-', len);
		n = -n;
	}

	if (n / 10)
		print_number(n / 10, len);
	printc(n % 10 + '0', len);
}
