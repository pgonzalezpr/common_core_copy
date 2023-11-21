/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:05:24 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/21 23:18:51 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_data {
	char	**map;
	int		width;
	int		height;
	int		exits;
	int		init_positions;
	int		collectionables;
}               t_data;

void	read_map(char *file, t_data *data);
void	check_map(t_data *data);
void	init_data(t_data *data);
void	exit_so_long(t_data *data, int status);
void	free_map(t_data *data);

#endif
