#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	offset;

	offset = 0;
	if (size > 0)
	{
		offset = 0;
		while (src[offset] && size > 1)
		{
			dst[offset] = src[offset];
			offset++;
			size--;
		}
		dst[offset] = '\0';
	}
	while (src[offset])
		offset++;
	return (offset);
}
