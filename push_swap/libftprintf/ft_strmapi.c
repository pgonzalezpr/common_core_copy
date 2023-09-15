#include "libftprintf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, (char)s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
