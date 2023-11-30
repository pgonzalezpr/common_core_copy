/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:05:42 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/28 19:30:16 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	check_extension(char *file)
{
	char	*ext_ptr;

	ext_ptr = ft_strchr(file, '.');
	if (!ext_ptr || ft_strlen(ext_ptr) != 4
		|| ft_strncmp(ext_ptr, ".ber", 4) != 0)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Error\nIncorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	check_extension(argv[1]);
	ft_memset(&data, 0, sizeof(t_data));
	data.width = -1;
	read_map(argv[1], &data);
	data.mlxp = mlx_init();
	data.winp = mlx_new_window(data.mlxp, data.width * TILE_SIZE, data.height
			* TILE_SIZE, "so_long");
	init_images(&data);
	render_textures(&data);
	mlx_key_hook(data.winp, &key_hook, &data);
	mlx_hook(data.winp, 17, 0, (void *)&exit_so_long, &data);
	mlx_loop(data.mlxp);
	exit_so_long(&data);
}
