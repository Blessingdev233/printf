#include "main.h"

/**
 * print_integer - print an integer
 * @list: list of arguments
 * @func: flags for the print function
 * Return: the length of printed in console
 */
int print_integer(va_list list, param_func *func)
{
	long i;
	int num_of_digits;

	/* check for mods */
	if (func->l_mod)
		i = va_arg(list, long);
	else if (func->h_mod)
		i = (short int) va_arg(list, int);
	else
		i = (int) va_arg(list, int);
	/* print the number */
	num_of_digits = print_num(convert_num(i, 10, 0, func), func);
	return (num_of_digits);
}

/**
*print_unsigned_integer - print an unsigned integer
*@list: list of arguments
*@func: flags for the print function
*Return: the length of printed in console
*/
int print_unsigned_integer(va_list list, param_func *func)
{
	unsigned long unsigned_num;

	if (func->l_mod)
		unsigned_num = (unsigned long)va_arg(list, unsigned long);
	else if (func->h_mod)
		unsigned_num = (unsigned short int)va_arg(list, unsigned int);
	else
		unsigned_num = (unsigned int)va_arg(list, unsigned int);
	func->unsign = 1;
	return (print_num(convert_num(unsigned_num, 10, FLAG_UNSIGNED, func), func));
}

/**
 * print_address - prints an address of a variable in hexa format
 * @list: list of arguments supllied
 * @func: pointer to flag functions
 * Return: the number/address of a variable
*/
int print_address(va_list list, param_func *func)
{
	char *s;
	unsigned long int address = va_arg(list, unsigned long int);

	if (!address)
		return (_puts("(nil)"));
	s = convert_num(address, 16, FLAG_LOWERCASE | FLAG_UNSIGNED, func);
	*--s = 'x';
	*--s = '0';
	return (print_num(s, func));
}
