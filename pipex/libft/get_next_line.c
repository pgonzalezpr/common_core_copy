/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:19:30 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/17 13:59:58 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static int	g_buffer_size = 42;

static char	*extract_saved(char *line)
{
	int		i;
	char	*saved;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	saved = ft_strdup(line + i + 1);
	if (*saved == '\0')
	{
		free(saved);
		saved = NULL;
	}
	line[i + 1] = '\0';
	return (saved);
}

static char	*build_line(int fd, char *saved, char *buff)
{
	ssize_t	read_values;
	char	*tmp;

	read_values = 1;
	while (read_values != 0)
	{
		read_values = read(fd, buff, g_buffer_size);
		if (read_values == -1)
		{
			free(saved);
			return (NULL);
		}
		else if (read_values == 0)
			break ;
		if (!saved)
			saved = ft_strdup("");
		tmp = saved;
		buff[read_values] = '\0';
		saved = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(saved, '\n'))
			break ;
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;
	char		*buff;

	if (fd < 0 || g_buffer_size <= 0)
		return (NULL);
	buff = malloc((g_buffer_size + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	line = build_line(fd, saved, buff);
	free(buff);
	buff = NULL;
	if (!line)
	{
		saved = NULL;
		return (NULL);
	}
	saved = extract_saved(line);
	return (line);
}

/*int main(void)
{
	int		fd;
	char	*line;

	//fd = open("read_error.txt", O_RDONLY);
	fd = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
	}
	printf("\n");
	close(fd);
}
*/
