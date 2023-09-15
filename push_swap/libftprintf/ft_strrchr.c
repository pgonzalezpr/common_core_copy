#include "libftprintf.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_last;

	s_last = NULL;
	while (*s)
	{
		if (*s == c)
			s_last = ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (s_last);
}
