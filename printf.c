#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: type constant char input, conversion specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	print_t spec[] = {
		{"c", printf_char}, {"s", printf_string},
		{"%", printf_percent}, {"d", printf_int}, {"i", printf_int},
		{"b", printf_binary}, {"r", printf_reverse},
		{"R", printf_rot13}, {"S", printf_str}
	};
	int i, j, _count = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	i = 0;
start:
	while (format && format[i])
	{
		j = 0;
		while (j < 9)
		{
			if (format[i] == '%' && format[i + 1] == spec[j].p[0])
			{
				_count += spec[j].f(args);
				i += 2;
				if (format[i] == '%' && format[i + 1] == '%')
				{
					i++;
					break;
				}
				else
					goto start;
			}
			j++;
		}
		_count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (_count);
}
