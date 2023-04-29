#include "main.h"

/**
 * _printf - a variadic function that can print an unknown number of args
 * @format: The argument to parse
 * Return: It returns the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	const char *c;
	int len;

	va_start(args, format);
	c = format;
	len = 0; /* length of the printf characters */

	if (c  == NULL)
		return (-1);
	while (*c != '\0')
	{
		if (*c == '%' && *(c + 1) == '\0')
			return (-1);
		if (*c == '%' && *(c + 1) != '\0')
		{
			switch (*(++c))
			{
			case 'c':
				PRINT(va_arg(args, int));
				break;
			case 's':
				len = print_str(va_arg(args, char *), len - 1);
				break;
			case '%':
				PRINT(*c);
				break;
			default:
				PRINT(*(c - 1));
				PRINT(*c);
				len++;
				break;
			}
		}
		else
			PRINT(*c);
		len++;
		c++;
	}
	return (len);
}
