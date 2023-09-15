#include "utils.h"

int	handle_int(int nbr)
{
	char	*nbr_str;
	int		len;

	ft_putnbr_fd(nbr, 1);
	nbr_str = ft_itoa(nbr);
	len = ft_strlen(nbr_str);
	free(nbr_str);
	return (len);
}

int	putnbr_base(unsigned long nbr, char *base)
{
	char	buffer[65];
	size_t	offset;
	size_t	base_len;
	size_t	nbr_len;

	offset = 64;
	base_len = ft_strlen(base);
	buffer[offset--] = '\0';
	while (nbr >= base_len)
	{
		buffer[offset--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	if (nbr == 0)
		buffer[offset] = base[0];
	else
		buffer[offset] = base[nbr % base_len];
	nbr_len = ft_strlen(buffer + offset);
	ft_putstr_fd(buffer + offset, 1);
	return (nbr_len);
}

int	handle_string(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	handle_pointer(void *ptr)
{
	unsigned long	ptr_nbr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ptr_nbr = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	return (putnbr_base(ptr_nbr, "0123456789abcdef") + 2);
}

int	convert(const char conv, va_list args)
{
	if (conv == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (conv == 's')
		return (handle_string(va_arg(args, char *)));
	if (conv == 'p')
		return (handle_pointer(va_arg(args, void *)));
	if (conv == 'u')
		return (putnbr_base(va_arg(args, unsigned int), "0123456789"));
	if (conv == 'd' || conv == 'i')
		return (handle_int(va_arg(args, int)));
	if (conv == 'x')
		return (putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (conv == 'X')
		return (putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (conv == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
