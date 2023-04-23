#include "main.h"
/**
 * print_number - prints an integer
 * @n: the integer to print
 * Return: Nothing
 */
void print_number(int n)
{
	if (n < 0)
	{
		printc('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);
	printc(n % 10 + '0');
}
