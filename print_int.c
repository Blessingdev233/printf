#include "main.h"

/**
 * _print_int - print an integer value
 * @n: An integer
 *
 * Return: The number of printed char
 */
int _print_int(int n)
{
	int _n = 0;
	int n_printed = 0;
	int digit = 0;

	if (n < 0)
	{
		n = -n;
		if (_putchar('-') != -1)
			n_printed++;
	}

	while (n > 0)
	{
		_n = _n * 10 + (n % 10);
		n /= 10;
	}

	n = _n;

	do {
		digit = n % 10;
		if (_putchar('0' + digit) != -1)
			n_printed++;
		n /= 10;
	} while (n > 0);

	return (n_printed);
}
