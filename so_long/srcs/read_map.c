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
		exit_so_long(data, EXIT_FAILURE);
	}
}

void	add_map_line(char *line, t_data *data)
{
	char	**new_map;
	int		i;

	new_map = malloc((data->height + 1) * sizeof(char *));
	if (!new_map)
		exit_so_long(data, EXIT_FAILURE);
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
		ft_dprintf(STDERR_FILENO, "Error\n");
		perror(file);
		exit_so_long(data, EXIT_FAILURE);
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
	check_valid_path(data);
}
