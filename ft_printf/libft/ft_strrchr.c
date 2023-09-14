#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_last;

	s_last = NULL;
	while (*s)
	{
		if (*s == (char) c)
			s_last = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (s_last);
}
