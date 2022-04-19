#include "main.h"

/**
 * print_percentage - prints a percent
 * @list: arguments from _printf
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percentage(va_list list, param_func *func)
{
	(void)list;
	(void)func;
	_putchar('%');
	return (1);
}

/**
 * print_stringUpper - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @list: arguments from _printf
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_stringUpper(va_list list, param_func *func)
{
	int count = 0;
	char *str;
	char *v_arg;

	v_arg = va_arg(list, char *);
	if ((int)(!v_arg))
		return (_puts("(null)"));

	for (; *v_arg; v_arg++)
	{
		if ((*v_arg > 0 && *v_arg < 32) || *v_arg >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			str = convert_num(*v_arg, 16, 0, func);
			if (!str[1])
				count += _putchar('0');
			count += _puts(str);
		}
		else
			count += _putchar(*v_arg);
	}
	return (count);
}

/**
 * print_reverse - prints string in reverse
 * @list: arguments from _printf
 * @func: the parameters struct
 *
 * Return: number bytes printed
 */
int print_reverse(va_list list, param_func *func)
{
	int len, count = 0;
	char *str = va_arg(list, char *);
	(void)func;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			count += _putchar(*str);
	}
	return (count);
}
/**
* print_rot13 - prints a string in rot13
*@list: arguments from _printf
*@func: pointer to the struct flags in which we turn the flags on
*Return: number of char printed
*/
int print_rot13(va_list list, param_func *func)
{
	int i, index;
	int count = 0;

	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(list, char *);
	(void)func;

	i = 0;
	index = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			index = str[i] - 65;
			count += _putchar(array[index]);
		}
		else
			 count += _putchar(str[i]);
		 i++;
	}
	return (count);
}

