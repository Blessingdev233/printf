#include "main.h"

/**
 * print_num - prints a number send to this function
 * @str: number to be printed
 * @func: name of the function that called this function
 * Return: The number of arguments printed
 */
int print_num(char *str, param_func *func)
{
	unsigned int i = _strlen(str);
	int neg = (!func->unsign && *str == '-');

	if (!func->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (func->precision != UINT_MAX)
		while (i++ < func->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!func->minus_flag)
		return (print_right_shift(str, func));
	else
		return (print_left_shift(str, func));
}

/**
 * convert_num - converts number and base into string
 * @num: input number
 * @base: input base
 * @flags: flag if hexa values need to be lowercase
 * @func: name of the function that called this function
 * Return: result string
 */
char *convert_num(long int num, int base, int flags, param_func *func)
{
	static char *array;
	static char buffer[50];
	char *str_lowercase;
	char *str_uppercase;
	char *ptr;
	char sign = 0;
	unsigned long n = num;
	(void)func;


	str_lowercase = "0123456789abcdef";

	str_uppercase = "0123456789ABCDEF";

	if (!(flags & FLAG_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = flags & FLAG_LOWERCASE ? str_lowercase : str_uppercase;
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * is_digit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_right_shift - prints a number with options
 * @str: the base number as a string
 * @func: the parameter struct
 *
 * Return: chars printed
 */
int print_right_shift(char *str, param_func *func)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (func->zero_flag && !func->minus_flag)
		pad_char = '0';
	neg = neg2 = (!func->unsign && *str == '-');
	if (neg && i < func->width && pad_char == '0' && !func->minus_flag)
		str++;
	else
		neg = 0;
	if ((func->plus_flag && !neg2) ||
	    (!func->plus_flag && func->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (func->plus_flag && !neg2 && pad_char == '0' && !func->unsign)
		n += _putchar('+');
	else if (!func->plus_flag && func->space_flag && !neg2 &&
		 !func->unsign && func->zero_flag)
		n += _putchar(' ');
	while (i++ < func->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (func->plus_flag && !neg2 && pad_char == ' ' && !func->unsign)
		n += _putchar('+');
	else if (!func->plus_flag && func->space_flag && !neg2 &&
		 !func->unsign && !func->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_left_shift - prints a number with options
 * @str: the base number as a string
 * @func: the parameter struct
 *
 * Return: chars printed
 */
int print_left_shift(char *str, param_func *func)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (func->zero_flag && !func->minus_flag)
		pad_char = '0';
	neg = neg2 = (!func->unsign && *str == '-');
	if (neg && i < func->width && pad_char == '0' && !func->minus_flag)
		str++;
	else
		neg = 0;

	if (func->plus_flag && !neg2 && !func->unsign)
		n += _putchar('+'), i++;
	else if (func->space_flag && !neg2 && !func->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < func->width)
		n += _putchar(pad_char);
	return (n);
}
