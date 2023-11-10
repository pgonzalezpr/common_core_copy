#include "../include/utils_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;
	write(1, "Hello ft_printf bonus!\n", 23);
	while (*format)
	{
		write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}