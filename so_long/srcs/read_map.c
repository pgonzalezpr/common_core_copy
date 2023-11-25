/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:26 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/25 12:04:27 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_line(char *line, t_data *data)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (data->width == -1)
		data->width = len;
	else if (len != data->width)
	{
		ft_dprintf(STDERR_FILENO, "Error\nNot rectangular map\n");
		free(line);
		exit_so_long(data);
	}
}

void	add_map_line(char *line, t_data *data)
{
	char	**new_map;
	int		i;

	new_map = malloc((data->height + 1) * sizeof(char *));
	if (!new_map)
		exit_so_long(data);
	i = 0;
	while (i < data->height)
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[i] = line;
	if (data->map)
		free(data->map);
	data->map = new_map;
	data->height++;
}

void	read_map(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error\nFile Error\n");
		exit_so_long(data);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		validate_line(line, data);
		add_map_line(line, data);
	}
	close(fd);
	check_walls(data);
	check_components(data);
	data->map_copy = dup_map(data);
	check_valid_path(data);
	free_map(data->map, data->height);
	data->map = data->map_copy;
	data->map_copy = NULL;
}
