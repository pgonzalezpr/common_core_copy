#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total_len = dst_len + src_len;
	if (size > dst_len)
	{
		dst += dst_len;
		size -= dst_len;
		if (src_len >= size)
			src_len = size - 1;
		ft_memcpy(dst, src, src_len);
		dst[src_len] = '\0';
		return (total_len);
	}
	else
		dst_len = size;
	return (dst_len + src_len);
}
