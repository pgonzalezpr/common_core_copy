#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_copy;

	dest_copy = dest;
	while (n > 0)
	{
		*((char *)dest++) = *((char *)src++);
		n--;
	}
	return (dest_copy);
}
