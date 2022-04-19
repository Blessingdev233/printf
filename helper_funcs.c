#include "main.h"

/**
 * get_mods - finds the modifier func
 * @str: the format string
 * @func: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_mods(char *str, param_func *func)
{
	int i = 0;

	switch (*str)
	{
		case 'h':
			i = func->h_mod = 1;
			break;
		case 'l':
			i = func->l_mod = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @str: the format string
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *str, param_func *func, va_list list)
{
	int i = 0;

	if (*str == '*')
	{
		i = va_arg(list, int);
		i++;
	}
	else
	{
		while (is_digit(*str))
			i = i * 10 + (*str++ - '0');
	}
	func->width = i;
	return (str);
}

/**
 * get_precision - gets the precision from the format string
 * @str: the format string
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *str, param_func *func, va_list list)
{
	int i = 0;

	if (*str != '*')
		return (str);
	str++;
	if (*str == '*')
	{
		i = va_arg(list, int);
		str++;
	}
	else
	{
		while (is_digit(*str))
			i = i * 10 + (*str++ - '0');

	}
	func->precision = i;
	return (str);
}
