#include "../include/pipex_bonus.h"

int	ft_strequals(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
		return (1);
	return (0);
}

void	print_str_arr(char **arr)
{
	int	i;

	if (!arr)
		ft_printf("NULL\n");
	else
	{
		i = 0;
		while (arr[i])
		{
			ft_printf("%s ", arr[i]);
			i++;
		}
		ft_printf("\n");
	}
}

void	print_args(char ***args)
{
	int	i;

	if (!args)
		ft_printf("NULL\n");
	else
	{
		i = 0;
		while (args[i])
		{
			print_str_arr(args[i]);
			i++;
		}
	}
}

void	print_pipex(t_pipex *pipex_data)
{
	ft_printf("in_fd: %i\n", pipex_data->in_fd);
	ft_printf("out_fd: %i\n", pipex_data->out_fd);
	ft_printf("here_doc: %i\n", pipex_data->here_doc);
	print_str_arr(pipex_data->cmd_paths);
	print_args(pipex_data->cmd_args);
	ft_printf("cmd_count: %i\n", pipex_data->cmd_count);
}
