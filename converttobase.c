#include <stdlib.h>
#include <stddef.h>
/**
 * *converttobase - convert number
 * @n: number
 * @b: base
 * Return: pointer to string
 */
char *converttobase(unsigned int n, int b)
{
	char rep[] = "0123456789ABCDEF";
	char *buf, *ptr;

	buf = malloc(50);
	if (buf == NULL)
		return (NULL);
	ptr = &buf[49];
	*ptr = '\0';
	do {
		*--ptr = rep[n % b];
		n /= b;
	} while (n != 0);
	return (ptr);
}
