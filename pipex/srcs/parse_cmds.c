/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:29 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:18:30 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

char	*get_bin_path(char *cmd, char **bin_paths)
{
	char	*path;

	if (!cmd || !bin_paths)
		return (NULL);
	while (*bin_paths)
	{
		path = build_path(cmd, *bin_paths);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		bin_paths++;
	}
	return (NULL);
}

int	get_paths(char **inputs, int cmd_count, char **cmd_paths, char **bin_paths)
{
	int		i;
	char	*path;
	char	**tokens;

	i = 0;
	while (i < cmd_count)
	{
		tokens = ft_split(inputs[i], ' ');
		if (!tokens)
			break ;
		path = get_bin_path(tokens[0], bin_paths);
		if (!path)
		{
			ft_printf("Error. Command not found: %s\n", tokens[0]);
			break ;
		}
		*cmd_paths = path;
		cmd_paths++;
		i++;
	}
	free_str_arr(tokens);
	free_str_arr(bin_paths);
	if (i < cmd_count)
		return (0);
	return (1);
}

void	parse_cmds(char **argv, int argc, char **envp, t_pipex *pipex_data)
{
	char	**cmd_paths;
	char	**bin_paths;

	pipex_data->cmd_count = argc - 3 - pipex_data->here_doc;
	cmd_paths = malloc((pipex_data->cmd_count + 1) * sizeof(char *));
	if (!cmd_paths)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->cmd_paths = cmd_paths;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			bin_paths = ft_split(*envp + 5, ':');
			if (!bin_paths)
				exit_pipex(pipex_data, EXIT_FAILURE);
		}
		envp++;
	}
	if (!get_paths(argv + 2 + pipex_data->here_doc, pipex_data->cmd_count,
			cmd_paths, bin_paths))
		exit_pipex(pipex_data, EXIT_FAILURE);
	cmd_paths[pipex_data->cmd_count] = NULL;
}
