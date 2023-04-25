#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 *formatstr - format string
 * @str: string pointer
 * @len: int pointer
 * Return: nothing
 */
void formatstr(char *str, int *len)
{
	int j = 0;

	while (str[j])
	{
		printc(str[j], len);
		j++;
	}
}


/**
 * conversionhandle - convert specifiers
 * @format: string
 * @i: position
 * @args: var args
 * @flen: integer pointer
 * Return: Nothing
 */
void conversionhandle(const char *format, int i, va_list args, int *flen)
{
	int integ;
	char *str;

	switch (format[i])
	{
		case '%':
			printc(format[i], flen);
			break;
		case 'c':
			printc(va_arg(args, int), flen);
			break;
		case 's':
			str = va_arg(args, char*);
			if (str == NULL)
				str = "(null)";
			formatstr(str, flen);
			break;
		case 'i':
		case 'd':
			integ = va_arg(args, int);
			print_number(integ, flen);
			break;
		default:
			printc('%', flen);
			printc(format[i], flen);
			break;

	}
}
/**
 * _printf - produces output according to a format
 * @format: a pointer to string
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	int i = 0, flen = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		while (format[i] && format[i] != '%')
		{
			printc(format[i], &flen);
			i++;
		}
		if (!format[i] || !format[i + 1])
			break;
		i++;
		conversionhandle(format, i, args, &flen);
	}
	va_end(args);
	return (flen);
}
