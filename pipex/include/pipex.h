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
void		exec_pipex(t_pipex *pipex_data);
char		**ft_shell_split(char const *s, char c);

#endif
