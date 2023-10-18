#include "main.h"
#include <stdio.h>
/**
 * printf_binary - converts unsigned int to binary
 * @args: argumets passed to the function
 * Return: number of printed charcters
 */
int printf_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i = 0, j = 0, k, binary[33];

	if (num == 0)
	{
		i += _putchar('0');
	}
	else
	{
		while (num > 0)
		{
			binary[j] = num % 2;
			num /= 2;
			j++;
		}
		binary[j] = '\0';
		for (k = (j - 1); k >= 0 ; k--)
		{
			i += _putchar(binary[k] + '0');
		}
	}
	return (i);
}

/**
 * printf_reverse - prints the reversed string
 * @args: argument passed to the function
 * Return: number of printed characters
 */
int printf_reverse(va_list args)
{
	char *str = va_arg(args, char*);
	int i, j;

	if (str == NULL)
		str = "";
	for (i = 0 ; str[i] != '\0' ; i++)
		;
	for (j = (i - 1) ; j >= 0 ; j--)
	{
		_putchar(str[j]);
	}
	return (i);
}

/**
 * printf_rot13 - prints the rot13'ed string
 * @args: argument passed to the function
 * Return: number of printed characters
 */
int printf_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, j;
	char letter[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char rotter[] = "NnOoPpQqRrSsTtUuVvWwXxYyZzAaBbCcDdEeFfGgHhIiJjKkLlMm";

	if (str == NULL)
		str = "";
	for (i = 0; str[i] != '\0' ; i++)
	{
		for (j = 0 ; letter[j] != '\0' ; j++)
		{
			if (str[i] == letter[j])
			{
				_putchar(rotter[j]);
				break;
			}
		}
		if (str[i] != letter[j])
		{
			_putchar(str[i]);
		}
	}
	return (i);
}
