/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:17:50 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:17:51 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	read_write_pipe(t_pipex *pipex_data, int out_fd, int end[])
{
	int		read_values;
	char	buffer[1024];

	read_values = read(end[0], &buffer, sizeof(buffer));
	while (read_values > 0)
	{
		if (write(out_fd, &buffer, read_values) == -1)
		{
			close(out_fd);
			exit_pipex(pipex_data, EXIT_FAILURE);
		}
		read_values = read(end[0], &buffer, sizeof(buffer));
	}
	close(end[0]);
	if (read_values == -1)
	{
		close(out_fd);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
}

void	parent(t_pipex *pipex_data, int index, int end[], pid_t p_id)
{
	int	status;
	int	out_fd;

	close(end[1]);
	waitpid(p_id, &status, 0);
	if (!WIFEXITED(status) || WEXITSTATUS(status) == EXIT_FAILURE)
		exit_pipex(pipex_data, EXIT_FAILURE);
	if (index == pipex_data->cmd_count - 1)
		out_fd = pipex_data->out_fd;
	else
	{
		out_fd = open(TMP_FILE, O_WRONLY | O_TRUNC);
		if (out_fd == -1)
			exit_pipex(pipex_data, EXIT_FAILURE);
	}
	read_write_pipe(pipex_data, out_fd, end);
}

void	child(t_pipex *pipex_data, int index, int end[])
{
	int	in_fd;

	close(end[0]);
	if (index == 0)
		in_fd = pipex_data->in_fd;
	else
	{
		in_fd = open(TMP_FILE, O_RDONLY);
		if (in_fd == -1)
			exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(end[1], STDOUT_FILENO) == -1)
	{
		close(in_fd);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
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
		child(pipex_data, index, end);
	else
		parent(pipex_data, index, end, p_id);
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
