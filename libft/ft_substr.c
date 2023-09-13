#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	while (*s && start > 0)
	{
		s++;
		start--;
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
