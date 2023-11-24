# include "../include/so_long.h"
#include <unistd.h>

int	move(t_data *data, int x, int y)
{
	ft_dprintf(STDOUT_FILENO, "x: %d, y: %d, player_x: %d, player_y: %d, map_x_y: %c\n", 
			x, y, data->player_x, data->player_y, data->map[x][y]);
	if (data->map[x][y] == 'E' && data->collectables == 0)
	{
		data->movements++;
		ft_dprintf(STDOUT_FILENO, "Movements: %d\n", data->movements);
		ft_dprintf(STDOUT_FILENO, "You have won!\n");
		exit_so_long(data, EXIT_SUCCESS);
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

	ft_dprintf(STDOUT_FILENO, "Keyhook: %d\n", keycode);
	value = 0;
	if (keycode == 65307)
		exit_so_long(data, EXIT_SUCCESS);
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
		ft_dprintf(STDOUT_FILENO, "x: %d, y: %d\n", 
				data->player_x, data->player_y);
	}
	return (1);
}
