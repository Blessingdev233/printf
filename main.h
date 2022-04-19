#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

/**
 * struct func_type - type structure
 * @t: pointer to the argument
 * @f: pointer-function associated with the argumen
 */
typedef struct func_type
{
	char *t;
	int (*f)(va_list);
} func_t;

int (*get_func(const char *format))(va_list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_str(va_list args);
int print_char(va_list args);
int print_pct(va_list args);
int _print_int(int n);
int _print_int_arg(va_list args);
int print_dec(va_list args);

#endif /* MAIN_H */
