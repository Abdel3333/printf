#include <stdlib.h>
/**
 * *converttobase - convert number
 * @n: number
 * @b: base
 * Return: pointer to string
 */
char *converttobase(unsigned int n, int b)
{
	char rep[] = "0123456789ABCDEF";
	char *buf = malloc(50), *ptr;

	ptr = &buf[49];
	*ptr = '\0';
	do {
		*--ptr = rep[n % b];
		n /= b;
	} while (n != 0);
	return (ptr);
}
