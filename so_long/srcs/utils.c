#include "../include/so_long.h"
#include <unistd.h>

char	**dup_map(t_data *data)
{
	char	**map_copy;
	int		x;

	map_copy = malloc(data->height * sizeof(char *));
	if (!map_copy)
		exit_so_long(data, EXIT_FAILURE);
	x = 0;
	while (x < data->height)
	{
		map_copy[x] = ft_strdup(data->map[x]);
		x++;
	}
	return (map_copy);
}

void	print_map(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->height)
	{
		ft_dprintf(STDOUT_FILENO, "%s", data->map[x]);
		x++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_copy = NULL;
	data->width = -1;
	data->height = 0;
	data->exits = 0;
	data->init_positions = 0;
	data->collectables = 0;
	data->player_x = -1;
	data->player_y = -1;
	data->movements = 0;
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	exit_so_long(t_data *data, int status)
{
	free_map(data->map, data->height);
	free_map(data->map_copy, data->height);
	exit(status);
}
