#include "../include/pipex_bonus.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex_data;

	pipex_data = init_pipex();
	if (!pipex_data)
		return (0);
	if (!check_args(argv, argc, pipex_data))
	{
		clean_pipex(pipex_data);
		return (0);
	}
	print_pipex(pipex_data);
	clean_pipex(pipex_data);
}
