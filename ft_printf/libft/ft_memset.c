#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (n > 0)
	{
		*s_copy = c;
		s_copy++;
		n--;
	}
	return (s);
}
