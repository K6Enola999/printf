#include "main.h"

/**
 * printf_char - prints a character to the standard output
 * @args: argument passed to the function
 * Return: number of characters printed
 */
int printf_char(va_list args)
{
	char character = va_arg(args, int);

	_putchar(character);
	return (1);
}

/**
 * printf_string - prints a string to the standard output
 * @args: the argument passed to the function
 * Return: number of charcaters printed
 */
int printf_string(va_list args)
{
	int i = 0;
	const char *str = va_arg(args, char *);

	if (str == NULL)
		return (0);
	for (; *(str + i) != '\0' ; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * printf_percent - prints the percent sign "%"
 * @args: arguments to be passed to function
 * Return: number of characters printed
 */
int printf_percent(va_list args)
{
	va_arg(args, int);
	_putchar('%');
	return (1);
}

/**
 * printf_int - prints an integer as a signed decimal number
 * @args: the argument passed to the function
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int num = va_arg(args, int);
	int i = 0, div = 1, digit, last_digit;

	last_digit = num % 10;
	num /= 10;
	if (last_digit < 0)
	{
		i += _putchar('-');
		num *= -1;
		last_digit *= -1;
	}
	if (num > 0)
	{
		while (div <= num)
		{
			div *= 10;
		}
		div /= 10;
		while (div > 0)
		{
			digit = num / div;
			i += _putchar(digit + '0');
			num %= div;
			div /= 10;
		}
	}
	i += _putchar(last_digit + '0');
	return (i);
}
