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

void	exec_cmd(t_pipex *pipex_data, int index)
{
	char	*cmd;
	char	*path;
	char	*err_msg;

	cmd = pipex_data->cmd_args[index][0];
	path = get_bin_path(cmd, pipex_data->cmd_paths);
	if (!path)
	{
		err_msg = ft_strjoin(cmd, ": command not found\n");
		if (!err_msg)
			exit_pipex(pipex_data, EXIT_FAILURE);
		write(2, err_msg, ft_strlen(err_msg));
		free(err_msg);
		exit_pipex(pipex_data, EXIT_CMD_NOT_FOUND);
	}
	execve(path, pipex_data->cmd_args[index], pipex_data->envp);
	error("execve", pipex_data);
}

void	exec_child(t_pipex *pipex_data, int index)
{
	dup_input(pipex_data, index);
	dup_output(pipex_data, index);
	close_pipes(pipex_data);
	exec_cmd(pipex_data, index);
}

pid_t	create_child(t_pipex *pipex_data, int index)
{
	pid_t	child_id;

	child_id = fork();
	if (child_id < 0)
		error("fork", pipex_data);
	else if (child_id == 0)
	{
		if (index == -1)
			here_doc(pipex_data);
		else
			exec_child(pipex_data, index);
	}
	if (index == -1)
		waitpid(child_id, NULL, 0);
	return (child_id);
}

void	exec_pipex(t_pipex *pipex_data)
{
	pid_t	p_id;
	int		index;
	int		status;

	init_pipes(pipex_data);
	if (pipex_data->here_doc)
		index = -1;
	else
		index = 0;
	p_id = -1;
	while (index < pipex_data->cmd_count)
	{
		p_id = create_child(pipex_data, index);
		index++;
	}
	close_pipes(pipex_data);
	waitpid(p_id, &status, 0);
	exit_pipex(pipex_data, WEXITSTATUS(status));
}
