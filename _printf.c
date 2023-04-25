#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
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
 * *strtolowercase - transform to lower case
 * @str: string
 * Return: string pointer
 */
char *strtolowercase(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
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
		case 'b':
			formatstr(converttobase(va_arg(args, unsigned int), 2), flen);
			break;
		case 'o':
			formatstr(converttobase(va_arg(args, unsigned int), 8), flen);
			break;
		case 'X':
			formatstr(converttobase(va_arg(args, unsigned int), 16), flen);
			break;
		case 'x':
			formatstr(
			strtolowercase(converttobase(va_arg(args, unsigned int), 16)), 
			flen);
			break;
		case 'u':
			formatstr(converttobase(va_arg(args, unsigned int), 10), flen);
			break;
		case 'S':
			formatstr(custum_string(va_arg(args, char*)), flen);
			break;
		case 'r':
			print_rev(va_arg(args, char*), flen);
			break;
		case 'R':
			formatstr(rot13(va_arg(args, char*)), flen);
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
