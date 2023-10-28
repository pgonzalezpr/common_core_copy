/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:20:58 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:59 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "unistd.h"
# include <fcntl.h>
# include <sys/wait.h>

# define TMP_FILE "tmp.txt"
# define USR_INPUT_FILE "here_doc.txt"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}			t_pipex;

void		check_input(char **argv, int argc, t_pipex *pipex_data);
void		exit_pipex(t_pipex *pipex_data, int status);
t_pipex		*init_pipex(void);
void		print_pipex(t_pipex *pipex_data);
void		parse_cmds(char **argv, int argc, char **envp, t_pipex *pipex_data);
void		parse_args(char **argv, int argc, t_pipex *pipex_data);
void		free_str_arr(char **arr);
int			ft_strequals(char *str1, char *str2);
void		exec_pipex(t_pipex *pipex_data);

#endif
