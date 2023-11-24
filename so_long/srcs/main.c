/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:05:42 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/24 21:13:24 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>
#include <unistd.h>

/*
int	key_hook(int keycode, t_data *vars)
{
	if (!vars)
		return (1);
	ft_dprintf(STDOUT_FILENO, "Hello from key_hook %d !\n", keycode);
	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Error\nIncorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	init_data(&data);
	read_map(argv[1], &data);
	void	*mlxp = mlx_init();
	void	*winp = mlx_new_window(mlxp, data.width * 40, data.height * 40, "so_long");
	mlx_key_hook(winp, &key_hook, &data);
	mlx_loop(mlxp);
	exit_so_long(&data, EXIT_SUCCESS);
}
