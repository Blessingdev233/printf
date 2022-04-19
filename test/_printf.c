#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: A string
 *
 * Return: the of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, n_printed = 0, r = 0;
	int (*f)(va_list);
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
			r = _putchar(format[i++]);
		else
		{
			f = get_func(&format[++i]);
			if (f != NULL)
			{
				r = f(args);
				i++;
			}
			else
				r = _putchar(format[i - 1]);
		}

		if (r != -1)
			n_printed += r;
	}
	va_end(args);

	return (n_printed);
}
