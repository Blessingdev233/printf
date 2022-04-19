#include "main.h"

/**
 * print_dec - print a integer read from va_list
 * @args: A va_list object
 *
 * Return: The number of printed char
 */
int print_dec(va_list args)
{
	int n = 0, _n = 0, a = 0;
	int n_printed = 0;
	unsigned int digit = 1;

	n = va_arg(args, int);

	if (n < 0)
	{
		n_printed = n_printed + _putchar('-');
		a = n * -1;
	}
	else
		a = n;
	_n = a;
	while (_n > 9)
	{
		_n = _n / 10;
		digit = digit * 10;
	}
	while (digit >= 1)
	{
		n_printed = n_printed + _putchar(((a / digit) % 10) + '0');
		digit = digit / 10;
	}
	return (n_printed);
}
