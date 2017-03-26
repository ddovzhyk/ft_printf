#include "libftprintf.h"

int			ft_printf(const char *format, ...)
{
	va_list		f;
	char		*str;
	t_print		print;

	print.byte = 0;
	str = (char *)format;
	va_start(f, format);
	while (*str)
	{
		if (*str == '%')
		{
			clear_struct(&print);
			check_modificator(&str, f, &print);
			check_spec_char(&str, f, &print);
		}
		else
		{
			write(1, str, 1);
			print.byte++;
		}
		str++;
	}
	return (print.byte);
}
