#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex_data;

	pipex_data = init_pipex();
	check_input(argv, argc, pipex_data);
	parse_cmds(argv, argc, envp, pipex_data);
	parse_args(argv, argc, pipex_data);
	print_pipex(pipex_data);
	exec_pipex(pipex_data);
	exit_pipex(pipex_data, EXIT_SUCCESS);
}
=======

	/*
	if (!(argc && argv && envp))
		exit(EXIT_FAILURE);
	int fd = open(USR_INPUT_FILE, O_RDWR | O_CREAT,
			S_IRUSR | S_IWUSR);
	int fd2 = open(TMP_FILE, O_RDWR | O_CREAT,
			S_IRUSR | S_IWUSR);
	ft_printf("fd: %d, fd2: %d\n", fd, fd2);
	*/
}
>>>>>>> 3335eef271aed5da7755b390615f87319d92b65a
