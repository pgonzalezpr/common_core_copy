/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:34 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/25 23:51:07 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**dup_map(t_data *data)
{
	char	**map_copy;
	int		x;

	map_copy = malloc(data->height * sizeof(char *));
	if (!map_copy)
		exit_so_long(data);
	x = 0;
	while (x < data->height)
	{
		map_copy[x] = ft_strdup(data->map[x]);
		x++;
	}
	return (map_copy);
}

void	find_initial_position(t_data *data)
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

void	exit_so_long(t_data *data)
{
	if (data->winp)
		mlx_destroy_window(data->mlxp, data->winp);
	if (data->mlxp)
		free(data->mlxp);
	free_map(data->map, data->height);
	exit(EXIT_SUCCESS);
}
