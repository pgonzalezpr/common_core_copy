/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:19:49 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:50 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*build_path(char *cmd, char *dir)
{
	char	*path;
	char	*tmp;

	path = ft_strjoin(dir, "/");
	if (!path)
		return (NULL);
	tmp = path;
	path = ft_strjoin(path, cmd);
	free(tmp);
	if (!path)
		return (NULL);
	return (path);
}

char	*get_bin_path(char *cmd, char **cmd_paths)
{
	char	*path;

	if (!cmd || !cmd_paths)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*cmd_paths)
	{
		path = build_path(cmd, *cmd_paths);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		cmd_paths++;
	}
	return (NULL);
}

void	get_paths(char **envp, t_pipex *pipex_data)
{
	char	**cmd_paths;

	cmd_paths = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			cmd_paths = ft_split(*envp + 5, ':');
			if (!cmd_paths)
				exit_pipex(pipex_data, EXIT_FAILURE);
			break ;
		}
		envp++;
	}
	if (!cmd_paths)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->cmd_paths = cmd_paths;
}
