#include "../include/so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	check_valid_path(t_data *data)
{
	if (data)
		return ;
	return ;
}

void	check_walls(t_data *data)
{
	if (data)
		return ;
	return ;
}

void	check_character(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1' || data->map[x][y] == '0')
		return ;
	else if (data->map[x][y] == 'C')
		data->collectionables++;
	else if (data->map[x][y] == 'E')
		data->exits++;
	else if (data->map[x][y] == 'P')
		data->init_positions++;
	else
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid character: %c\n",
			data->map[x][y]);
		exit_so_long(data, EXIT_FAILURE);
	}
}

void	check_components(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			check_character(data, x, y);
			y++;
		}
		x++;
	}
	if (data->collectionables < 1 || data->exits != 1
		|| data->init_positions != 1)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "Collectionables, exits or positions\n");
		exit_so_long(data, EXIT_FAILURE);
	}
}

void	check_map(t_data *data)
{
	check_components(data);
	check_walls(data);
	check_valid_path(data);
}
