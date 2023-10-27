#include "../include/pipex.h"

void	parent_process(t_pipex *pipex_data, int index, int end[], pid_t p_id)
{
	int		status;
	int		out_fd;
	int		read_values;
	char	buffer[1024];

	waitpid(p_id, &status, 0);
	ft_printf("status: %d\n", status);
    out_fd = pipex_data->tmp_fd;
	if (index == pipex_data->cmd_count - 1)
		out_fd = pipex_data->out_fd;
	close(end[1]);
	read_values = read(end[0], &buffer, sizeof(buffer));
	while (read_values > 0)
	{
        ft_printf("pipex out_fd: %d, out_fd: %d\n", pipex_data->out_fd, out_fd);
        ft_printf("read values: %d\n", read_values);
        write(1, &buffer, read_values);
		if (write(out_fd, &buffer, read_values) == -1)
        	exit_pipex(pipex_data, EXIT_FAILURE);
		read_values = read(end[0], &buffer, sizeof(buffer));
        ft_printf("read values: %d\n", read_values);
	}
	close(end[0]);
	if (read_values == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
}

void	child_process(t_pipex *pipex_data, int index, int end[])
{
	int	in_fd;

    in_fd = pipex_data->tmp_fd;
	if (index == 0)
		in_fd = pipex_data->in_fd;
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(end[1], STDOUT_FILENO) == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	close(end[0]);
	if (execve(pipex_data->cmd_paths[index], pipex_data->cmd_args[index],
			NULL) == -1)
	{
		perror("Error executing command: ");
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd(t_pipex *pipex_data, int index)
{
	int		end[2];
	pid_t	p_id;

	if (pipe(end) == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	p_id = fork();
	if (p_id < 0)
	{
		perror("Error. Fork: ");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	else if (p_id == 0)
		child_process(pipex_data, index, end);
	else
		parent_process(pipex_data, index, end, p_id);
}

void	exec_pipex(t_pipex *pipex_data)
{
	int	index;

	index = 0;
	while (index < pipex_data->cmd_count)
	{
		exec_cmd(pipex_data, index);
		index++;
	}
}
