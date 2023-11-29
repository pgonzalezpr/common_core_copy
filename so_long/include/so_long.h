/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:05:24 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/28 19:33:24 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# define TILE_SIZE 30

typedef struct s_data
{
	char	**map;
	void	*mlxp;
	void	*winp;
	void	*player;
	void	*wall;
	void	*collectable;
	void	*exit;
	void	*empty;
	int		width;
	int		height;
	int		exits;
	int		init_positions;
	int		collectables;
	int		player_x;
	int		player_y;
	int		movements;
}			t_data;

void		read_map(char *file, t_data *data);
void		check_walls(t_data *data);
void		check_components(t_data *data);
void		check_valid_path(t_data *data);
void		exit_so_long(t_data *data);
void		free_map(char **map, int height);
void		print_map(t_data *data);
void		find_initial_position(t_data *data);
char		**dup_map(t_data *data);
int			key_hook(int keycode, t_data *data);
void		render_textures(t_data *data);
void		init_images(t_data *data);

#endif
