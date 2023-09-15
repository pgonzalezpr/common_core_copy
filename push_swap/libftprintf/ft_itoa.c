#include "libftprintf.h"

static int	number_of_digits(int n)
{
	int	digits;

	if (n > -10 && n < 10)
		return (1);
	digits = 0;
	while (n != 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

void	copy_nbr(unsigned int value, int offset, char *ptr, int sign)
{
	while (value >= 10)
	{
		ptr[offset--] = (value % 10) + '0';
		value = value / 10;
	}
	ptr[offset--] = value + '0';
	if (sign)
		ptr[offset] = '-';
}

char	*ft_itoa(int n)
{
	int				sign;
	char			*ptr;
	int				size;
	int				offset;
	unsigned int	value;

	sign = 0;
	value = n;
	if (n < 0)
	{
		sign = 1;
		value = -n;
	}
	size = number_of_digits(n) + sign + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	offset = size - 1;
	ptr[offset--] = '\0';
	copy_nbr(value, offset, ptr, sign);
	return (ptr);
}
