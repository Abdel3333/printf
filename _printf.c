#include <stdarg.h>
#include "main.h"

/**
 *formatstr - format string
 * @str: string pointer
 * Return: nothing
 */
void formatstr(char *str)
{
	while (str[j])
	{
		printc(str[j]);
		j++;
	}
}
/**
 * _printf - produces output according to a format
 * @format: a pointer to string
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	int i = 0, flen = 0, j = 0, integ;
	char *str;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		flen++;
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case '%':
					printc(format[i]);
					break;
				case 'c':
					printc(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					formatstr(str);
					break;
				/*
				*case 'i':
				*case 'd':
				*	integ = va_arg(args, int);
				*	print_number(integ);
				*	break;
				*/
			}
			i++;
		}
		else
			printc(format[i]);
	}
	va_end(args);
	return (flen);
}