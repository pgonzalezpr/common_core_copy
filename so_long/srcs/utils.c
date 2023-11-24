#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->width = -1;
	data->height = 0;
	data->exits = 0;
	data->init_positions = 0;
	data->collectables = 0;
	data->player_x = -1;
	data->player_y = -1;
	data->movements = 0;
}

void	free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (i < data->height)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	exit_so_long(t_data *data, int status)
{
	free_map(data);
	exit(status);
}
