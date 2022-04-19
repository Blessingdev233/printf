#include "main.h"


/**
 * _print_int_arg - print a integer from va_list
 * @args: A va_list object
 *
 * Return: The number of printed char
 */
int _print_int_arg(va_list args)
{
	return (_print_int(va_arg(args, int)));
}
