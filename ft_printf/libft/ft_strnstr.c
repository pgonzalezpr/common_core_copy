#include "libft.h"

int	compare_string(const char *big, const char *little, size_t len)
{
	while (*little && *big == *little && len > 0)
	{
		big++;
		little++;
		len--;
	}
	return (!*little);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		if (*big == *little && compare_string(big, little, len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
