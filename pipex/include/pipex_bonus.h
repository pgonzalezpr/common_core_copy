#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "unistd.h"
# include <fcntl.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}			t_pipex;

int			check_input(char **argv, int argc, t_pipex *pipex_data);
void		clean_pipex(t_pipex *pipex_data);
t_pipex		*init_pipex(void);
void		print_pipex(t_pipex *pipex_data);
int			ft_strequals(char *str1, char *str2);

#endif