#include <unistd.h>
/**
 * printc - print a character
 * @c: the char
 * @len: integer pointer
 * Return: an integer
 */
int printc(char c, int *len)
{
	*len += 1;
	return (write(1, &c, 1));
}
