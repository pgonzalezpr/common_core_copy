#include "libft.h"
#include "limits.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	value;
	int				sign;

	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	sign = 1;
	value = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - '0');
		nptr++;
	}
	return (value * sign);
}
