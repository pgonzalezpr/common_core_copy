/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:50 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:18:51 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	error(char *msg, t_pipex *pipex_data)
{
	perror(msg);
	exit_pipex(pipex_data, EXIT_FAILURE);
}

void	dup_input(t_pipex *pipex_data, int index)
{
	int	in_fd;

	if (index == 0)
	{
		in_fd = open(pipex_data->infile, O_RDONLY);
		if (in_fd == -1)
		{
			perror(pipex_data->infile);
			exit_pipex(pipex_data, EXIT_FAILURE);
		}
		if (dup2(in_fd, STDIN_FILENO) == -1)
			error("dup2", pipex_data);
		close(in_fd);
	}
	else
	{
		if (dup2(pipex_data->pipe_fds[index - 1][0], STDIN_FILENO) == -1)
			error("dup2", pipex_data);
	}
}

void	dup_output(t_pipex *pipex_data, int index)
{
	int	out_fd;

	if (index == pipex_data->cmd_count - 1)
	{
		if (pipex_data->here_doc)
			out_fd = open(pipex_data->outfile, O_WRONLY | O_CREAT | O_APPEND,
					0664);
		else
			out_fd = open(pipex_data->outfile, O_WRONLY | O_CREAT | O_TRUNC,
					0664);
		if (out_fd == -1)
		{
			perror(pipex_data->outfile);
			exit_pipex(pipex_data, EXIT_FAILURE);
		}
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			error("dup2", pipex_data);
		close(out_fd);
	}
	else
	{
		if (dup2(pipex_data->pipe_fds[index][1], STDOUT_FILENO) == -1)
			error("dup2", pipex_data);
	}
}

void	init_pipes(t_pipex *pipex_data)
{
	int	i;
	int	**pipe_fds;

	i = 0;
	pipe_fds = pipex_data->pipe_fds;
	while (i < pipex_data->cmd_count - 1)
	{
		pipe_fds[i] = malloc(2 * sizeof(int));
		if (!pipe_fds[i])
			exit_pipex(pipex_data, EXIT_FAILURE);
		if (pipe(pipe_fds[i]) == -1)
			error("pipe", pipex_data);
		i++;
	}
}

void	close_pipes(t_pipex *pipex_data)
{
	int	i;

	i = 0;
	while (i < pipex_data->cmd_count - 1)
	{
		close(pipex_data->pipe_fds[i][0]);
		close(pipex_data->pipe_fds[i][1]);
		i++;
	}
}
