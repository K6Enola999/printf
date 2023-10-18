#include "main.h"
#include <stdio.h>

/**
 * printf_str - prints the string
 * @args: argument passed to the function
 * Return: number of printed characters
 */
int printf_str(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count, reminder;
	char hex[] = {"0123456789ABCDEF"};

	if (str == NULL)
		str = 0;
	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar('0');
			reminder = str[i] % 16;
			count += _putchar(hex[reminder]);
		}
		else
			count += _putchar(str[i]);
	}
	return (i + (count - 1));
}
