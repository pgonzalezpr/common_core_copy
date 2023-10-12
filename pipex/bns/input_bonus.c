#include "../include/pipex_bonus.h"

int	check_permissions(char *infile, char *outfile, t_pipex *pipex_data)
{
	if (!pipex_data->here_doc)
	{
		if (access(infile, F_OK) != 0)
		{
			ft_printf("Error. File not found: %s\n", infile);
			return (0);
		}
		if (access(infile, R_OK) != 0)
		{
			ft_printf("Error. Permission denied: %s\n", infile);
			return (0);
		}
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) != 0)
	{
		ft_printf("Error. Permission denied: %s\n", outfile);
		return (0);
	}
	return (1);
}

int	check_args(char **argv, int argc, t_pipex *pipex_data)
{
	int	in_fd;
	int	out_fd;

	pipex_data->here_doc = ft_strequals(argv[1], "here_doc");
	if (argc < 5 || (pipex_data->here_doc && argc < 6))
	{
		ft_printf("Error. Incorrect number of arguments\n");
		return (0);
	}
	if (!check_permissions(argv[1], argv[argc - 1], pipex_data))
		return (0);
	if (!pipex_data->here_doc)
	{
		in_fd = open(argv[1], O_RDONLY);
		if (in_fd == -1)
			return (0);
		pipex_data->in_fd = in_fd;
	}
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT);
	if (out_fd == -1)
		return (0);
	pipex_data->out_fd = out_fd;
	return (1);
}
