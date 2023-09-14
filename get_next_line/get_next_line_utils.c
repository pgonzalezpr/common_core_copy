#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size - 1] = '\0';
	return (ptr);
}
