/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:34 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/25 12:04:35 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_memoize_arr(t_data *data)
{
	int	**arr;
	int	x;
	int	y;

	arr = malloc(data->height * sizeof(int *));
	if (!arr)
		exit_so_long(data);
	x = 0;
	while (x < data->height)
	{
		arr[x] = ft_calloc(sizeof(int), data->width);
		if (!arr[x])
			exit_so_long(data);
		y = 0;
		while (y < data->width)
		{
			arr[x][y] = -1;
			y++;
		}
		x++;
	}
	data->memo = arr;
}

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
	int	x;

	if (data->winp)
		mlx_destroy_window(data->mlxp, data->winp);
	if (data->mlxp)
		free(data->mlxp);
	free_map(data->map, data->height);
	free_map(data->map_copy, data->height);
	x = 0;
	if (data->memo)
	{
		while (x < data->height)
		{
			if (data->memo)
			{
				free(data->memo[x]);
				x++;
			}
		}
		free(data->memo);
	}
	exit(EXIT_SUCCESS);
}
