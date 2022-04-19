#include "main.h"

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: The length of the number printed
 */
int print_binary(va_list list, param_func *func)
{
	unsigned int binary_num;
	char *str;
	int len = 0;

	binary_num = va_arg(list, unsigned int);
	str = convert_num(binary_num, 2, FLAG_UNSIGNED, func);
	if (func->hash_flag && binary_num)
		*--str = '0';
	func->unsign = 1;

	return (len += print_num(str, func));
}

/**
 * print_hexa - print an hexadecimal number
 * @list: the number passed
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: the length of number printed
 */

int print_hexa(va_list list, param_func *func)
{
	unsigned long hex_num;
	char *hex_string;
	int i = 0;

	if (func->l_mod)
		hex_num = (unsigned long)va_arg(list, unsigned long);
	else if (func->h_mod)
		hex_num = (unsigned short int)va_arg(list, unsigned int);
	else
		hex_num = (unsigned int)va_arg(list, unsigned int);
	hex_string = convert_num(hex_num, 16, FLAG_UNSIGNED | FLAG_LOWERCASE, func);
	if (func->hash_flag && hex_num)
	{
		*--hex_string = 'x';
		*--hex_string = '0';
	}
	func->unsign = 1;
	return (i += print_num(hex_string, func));
}

/**
 * print_octal - print a number converted in octal
 * @list: the argument received
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: the length of printed in console
 */
int print_octal(va_list list, param_func *func)
{
	unsigned long num;
	int len = 0;
	char *oct_rep;

	if (func->l_mod)
		num = (unsigned long)va_arg(list, unsigned long);
	else if (func->h_mod)
		num = (unsigned short int)va_arg(list, unsigned int);
	else
		num = (unsigned int)va_arg(list, unsigned int);
	oct_rep = convert_num(num, 8, FLAG_UNSIGNED, func);
	if (func->hash_flag && num)
		*--oct_rep = '0';
	func->unsign = 1;

	return (len += print_num(oct_rep, func));
}

/**
 * print_heX - prints a number in hexadecimal base,
 * in uppercase
 * @list: va_list arguments from _printf
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: the length of printed in console
 */
int print_heX(va_list list, param_func *func)
{
	unsigned long hex_num;
	char *hex_string;
	int i = 0;

	if (func->l_mod)
		hex_num = (unsigned long)va_arg(list, unsigned long);
	else if (func->h_mod)
		hex_num = (unsigned short int)va_arg(list, unsigned int);
	else
		hex_num = (unsigned int)va_arg(list, unsigned int);
	hex_string = convert_num(hex_num, 16, FLAG_UNSIGNED | FLAG_LOWERCASE, func);
	if (func->hash_flag && hex_num)
	{
		*--hex_string = 'X';
		*--hex_string = '0';
	}
	func->unsign = 1;

	return (i += print_num(hex_string, func));
}
