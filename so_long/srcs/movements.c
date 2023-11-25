/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:19 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/25 23:55:58 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>

int	move(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'E' && data->collectables == 0)
	{
		data->movements++;
		ft_dprintf(STDOUT_FILENO, "Movements: %d\n", data->movements);
		ft_dprintf(STDOUT_FILENO, "You have won!\n");
		exit_so_long(data);
	}
	if (data->map[x][y] == '0' || data->map[x][y] == 'C')
	{
		if (data->map[x][y] == 'C')
			data->collectables--;
		data->movements++;
		data->map[x][y] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		data->player_x = x;
		data->player_y = y;
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int	value;

	value = 0;
	if (keycode == 65307)
		exit_so_long(data);
	if (keycode == 97)
		value = move(data, data->player_x, data->player_y - 1);
	if (keycode == 100)
		value = move(data, data->player_x, data->player_y + 1);
	if (keycode == 115)
		value = move(data, data->player_x + 1, data->player_y);
	if (keycode == 119)
		value = move(data, data->player_x - 1, data->player_y);
	if (value)
	{
		ft_dprintf(STDOUT_FILENO, "Movements: %d\n", data->movements);
		render_textures(data);
	}
	return (1);
}
