#include "main.h"

/**
 *_printf - Print a formatted string
 *@format: format string
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list list;
	char *pointer, *start;
	param_func flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (pointer = (char *)format; *pointer; pointer++)
	{
		init_params(&flags, list);
		if (*pointer != '%')
		{
			count += _putchar(*pointer);
			continue;
		}
		start = pointer;
		pointer++;
		while (get_flags(pointer, &flags))
		{
			pointer++;
		}
		pointer = get_width(pointer, &flags, list);
		pointer = get_precision(pointer, &flags, list);
		if (get_mods(pointer, &flags))
			pointer++;

		if (!func_parse(pointer))
			count += print_range(start, pointer,
			flags.l_mod || flags.h_mod ? pointer - 1 : 0);
		else
			count += print_func(pointer, list, &flags);
	}
	_putchar(-1);
	va_end(list);
	return (count);
}
