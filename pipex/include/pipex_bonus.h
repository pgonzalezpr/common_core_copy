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
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	int		here_doc;
	char	*delimiter;
	char	**cmd_paths;
	char	**envp;
	char	***cmd_args;
	int		**pipe_fds;
	int		cmd_count;
}			t_pipex;

# define EXIT_CMD_NOT_FOUND 127
# define TMP_FILE ".here_doc_tmp.txt"

void		check_input(char **argv, int argc, char **envp,
				t_pipex *pipex_data);
void		exit_pipex(t_pipex *pipex_data, int status);
t_pipex		*init_pipex(void);
void		get_paths(char **envp, t_pipex *pipex_data);
char		*get_bin_path(char *cmd, char **cmd_paths);
void		parse_args(char **argv, int argc, t_pipex *pipex_data);
void		free_str_arr(char **arr);
int			ft_strequals(char *str1, char *str2);
void		exec_pipex(t_pipex *pipex_data);
char		**ft_shell_split(char const *s, char c);
void		error(char *msg, t_pipex *pipex_data);
void		dup_input(t_pipex *pipex_data, int index);
void		dup_output(t_pipex *pipex_data, int index);
void		here_doc(t_pipex *pipex_data);
void		init_pipes(t_pipex *pipex_data);
void		close_pipes(t_pipex *pipex_data);

#endif
