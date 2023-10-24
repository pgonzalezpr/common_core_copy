#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex_data;

	pipex_data = init_pipex();
	check_input(argv, argc, pipex_data);
	parse_cmds(argv, argc, envp, pipex_data);
	parse_args(argv, argc, pipex_data);
	print_pipex(pipex_data);
	exit_pipex(pipex_data, EXIT_SUCCESS);
}
