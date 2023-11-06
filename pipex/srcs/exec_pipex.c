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

void	error(char *msg, t_pipex *pipex_data)
{
	perror(msg);
	exit_pipex(pipex_data, EXIT_FAILURE);
}

void	exec_cmd(t_pipex *pipex_data, char **envp, int index)
{
	char	*cmd;
	char	*path;

	cmd = pipex_data->cmd_args[index][0];
	path = get_bin_path(cmd, pipex_data->cmd_paths);
	if (!path)
	{
		ft_printf(STDERR_FILENO, "%s: command not found\n", cmd);
		exit_pipex(pipex_data, EXIT_CMD_NOT_FOUND);
	}
	execve(path, pipex_data->cmd_args[index], envp);
	error("execve", pipex_data);
}

void	second(t_pipex *pipex_data, char **envp, int pipe_fd[])
{
	int	out_fd;

	out_fd = open(pipex_data->outfile, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (out_fd == -1)
	{
		perror(pipex_data->outfile);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error("dup2", pipex_data);
	close(pipe_fd[1]);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		error("dup2", pipex_data);
	close(out_fd);
	exec_cmd(pipex_data, envp, 1);
}

void	first(t_pipex *pipex_data, char **envp, int pipe_fd[])
{
	int	in_fd;

	in_fd = open(pipex_data->infile, O_RDONLY);
	if (in_fd == -1)
	{
		perror(pipex_data->infile);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error("dup2", pipex_data);
	close(pipe_fd[0]);
	if (dup2(in_fd, STDIN_FILENO) == -1)
		error("dup2", pipex_data);
	close(in_fd);
	exec_cmd(pipex_data, envp, 0);
}

void	exec_pipex(t_pipex *pipex_data, char **envp)
{
	int		pipe_fd[2];
	pid_t	first_id;
	pid_t	second_id;
	int		status;

	if (pipe(pipe_fd) == -1)
		error("pipe", pipex_data);
	first_id = fork();
	if (first_id == -1)
		error("fork", pipex_data);
	if (first_id == 0)
		first(pipex_data, envp, pipe_fd);
	second_id = fork();
	if (second_id == -1)
		error("fork", pipex_data);
	if (second_id == 0)
	{
		waitpid(first_id, NULL, 0);
		second(pipex_data, envp, pipe_fd);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(second_id, &status, 0);
	exit_pipex(pipex_data, WEXITSTATUS(status));
}
