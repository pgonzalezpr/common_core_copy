/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:40:39 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/17 13:41:21 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_utils.h"

int	ft_printf_int(int nbr, int fd)
{
	char	*nbr_str;
	int		len;

	ft_putnbr_fd(nbr, fd);
	nbr_str = ft_itoa(nbr);
	len = ft_strlen(nbr_str);
	free(nbr_str);
	return (len);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int fd)
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
	ft_putstr_fd(buffer + offset, fd);
	return (nbr_len);
}

int	ft_printf_string(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}

int	ft_printf_pointer(void *ptr, int fd)
{
	unsigned long	ptr_nbr;

	if (!ptr)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	ptr_nbr = (unsigned long)ptr;
	ft_putstr_fd("0x", fd);
	return (ft_putnbr_base(ptr_nbr, "0123456789abcdef", fd) + 2);
}

int	convert(int fd, const char conv, va_list args)
{
	if (conv == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), fd);
		return (1);
	}
	if (conv == 's')
		return (ft_printf_string(va_arg(args, char *), fd));
	if (conv == 'p')
		return (ft_printf_pointer(va_arg(args, void *), fd));
	if (conv == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", fd));
	if (conv == 'd' || conv == 'i')
		return (ft_printf_int(va_arg(args, int), fd));
	if (conv == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				fd));
	if (conv == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				fd));
	if (conv == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	return (0);
}
