#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_path(t_data data, int x, int y, int collectables)
{
	int	og;

	og = data.map[x][y];
	if (data.map[x][y] == '1' || (data.map[x][y] == 'E'
			&& collectables != data.collectables))
		return (0);
	if (data.map[x][y] == 'E')
		return (1);
	if (data.map[x][y] == 'C')
		collectables++;
	data.map[x][y] = '1';
	if (check_path(data, x + 1, y, collectables))
		return (1);
	if (check_path(data, x - 1, y, collectables))
		return (1);
	if (check_path(data, x, y + 1, collectables))
		return (1);
	if (check_path(data, x, y - 1, collectables))
		return (1);
	data.map[x][y] = og;
	return (0);
}

void	check_valid_path(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			if (data->map[x][y] == 'P')
				break ;
			y++;
		}
		if (data->map[x][y] == 'P')
			break ;
		x++;
	}
	data->player_x = x;
	data->player_y = y;
	if (!check_path(*data, x, y, 0))
	{
		ft_dprintf(STDERR_FILENO, "Error\nMap contains no valid path\n");
		exit_so_long(data, EXIT_FAILURE);
	}
}

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		if (data->map[x][0] != '1' || data->map[x][data->width - 1] != '1')
		{
			ft_dprintf(STDERR_FILENO, "Error\nMap not surrounded by walls\n");
			exit_so_long(data, EXIT_FAILURE);
		}
		x++;
	}
	y = 0;
	while (y < data->width)
	{
		if (data->map[0][y] != '1' || data->map[data->height - 1][y] != '1')
		{
			ft_dprintf(STDERR_FILENO, "Error\nMap not surrounded by walls\n");
			exit_so_long(data, EXIT_FAILURE);
		}
		y++;
	}
}

void	check_character(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1' || data->map[x][y] == '0')
		return ;
	else if (data->map[x][y] == 'C')
		data->collectables++;
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
	if (data->collectables < 1 || data->exits != 1 || data->init_positions != 1)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "Collectionables, exits or positions\n");
		exit_so_long(data, EXIT_FAILURE);
	}
}
