#include "libftprintf.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (src < dest)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((char *)dest)[len] = ((char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((char *)dest)[len] = ((char *)src)[len];
			len++;
		}
	}
	return (dest);
}
