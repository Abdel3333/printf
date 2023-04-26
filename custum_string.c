#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * *custum_string - prints a string
 * @s: a pointer to the string
 * Return: Nothing
 */
char *custum_string(char *s)
{
	char *convstr, *ptr;

	ptr = malloc(sizeof(s));
	if (ptr == NULL)
		return (NULL);
	while (*s)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			ptr = realloc(ptr, 4);
			if (ptr == NULL)
				return (NULL);
			*(ptr++) = '\\';
			*(ptr++) = 'x';
			convstr = converttobase(*s, 16);
			while (*convstr)
				*(ptr++) = *(convstr++);
		}
		else
			*(ptr++) = *s;
		s++;
	}
	return (ptr);
}
