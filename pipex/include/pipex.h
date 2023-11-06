/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:20:51 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:52 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

# define EXIT_CMD_NOT_FOUND 127

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmd_paths;
	char	***cmd_args;
}			t_pipex;

void		check_input(char **argv, int argc, t_pipex *pipex_data);
void		exit_pipex(t_pipex *pipex_data, int status);
t_pipex		*init_pipex(void);
void		get_paths(char **envp, t_pipex *pipex_data);
void		free_str_arr(char **arr);
char		*get_bin_path(char *cmd, char **cmd_paths);
void		parse_args(char **argv, int argc, t_pipex *pipex_data);
void		exec_pipex(t_pipex *pipex_data, char **envp);
char		**ft_shell_split(char const *s, char c);

#endif
