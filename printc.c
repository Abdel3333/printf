#include <unistd.h>
/**
 * printc - print a character
 * @c: the char
 * Return: an integer
 */
int printc(char c)
{
	return (write(1, &c, 1));
}
