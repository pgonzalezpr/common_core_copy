#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr[12];
	int				len;
	unsigned int	value;

	len = 11;
	nbr[len--] = '\0';
	value = n;
	if (n < 0)
		value = -n;
	while (value >= 10)
	{
		nbr[len--] = (value % 10) + '0';
		value = value / 10;
	}
	nbr[len--] = (value % 10) + '0';
	if (n < 0)
		nbr[len--] = '-';
	ft_putstr_fd(nbr + len + 1, fd);
}
