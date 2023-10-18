#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct print - struct print
 * @p: type char pointer
 * @f: a pointer to function that takes va_list type parameter
 */
typedef struct print
{
	char *p;
	int (*f)(va_list args);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_percent(va_list args);
int printf_int(va_list args);
int printf_binary(va_list args);
int printf_reverse(va_list args);
int printf_rot13(va_list args);
int printf_str(va_list args);

#endif
