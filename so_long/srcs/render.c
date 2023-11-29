/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:58 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:24 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_data *data)
{
	int	h;
	int	w;

	data->player = mlx_xpm_file_to_image(data->mlxp, "images/player.xpm", &h,
			&w);
	data->wall = mlx_xpm_file_to_image(data->mlxp, "images/wall.xpm", &h, &w);
	data->collectable = mlx_xpm_file_to_image(data->mlxp,
			"images/collectable.xpm", &h, &w);
	data->exit = mlx_xpm_file_to_image(data->mlxp, "images/exit.xpm", &h, &w);
	data->empty = mlx_xpm_file_to_image(data->mlxp, "images/empty.xpm", &h, &w);
}

void	place_texture(t_data *data, int x, int y)
{
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlxp, data->winp, data->empty, 
				y * TILE_SIZE, x * TILE_SIZE);
	else if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlxp, data->winp, data->wall, 
				y * TILE_SIZE, x * TILE_SIZE);
	else if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlxp, data->winp, data->player, 
				y * TILE_SIZE, x * TILE_SIZE);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlxp, data->winp, data->collectable, y
			* TILE_SIZE, x * TILE_SIZE);
	else if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlxp, data->winp, data->exit, 
				y * TILE_SIZE, x * TILE_SIZE);
}

void	render_textures(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			place_texture(data, x, y);
			y++;
		}
		x++;
	}
}
