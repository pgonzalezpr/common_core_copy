/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:19:36 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:37 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_pipex	*init_pipex(void)
{
	t_pipex	*pipex_data;

	pipex_data = malloc(sizeof(t_pipex));
	if (!pipex_data)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->infile = NULL;
	pipex_data->outfile = NULL;
	pipex_data->here_doc = 0;
	pipex_data->delimiter = NULL;
	pipex_data->cmd_paths = NULL;
	pipex_data->cmd_args = NULL;
	pipex_data->cmd_count = 0;
	pipex_data->pipe_fds = NULL;
	return (pipex_data);
}

void	free_str_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_params(char ***args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free_str_arr(args[i]);
		i++;
	}
	free(args);
}

int	ft_strequals(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
		return (1);
	return (0);
}

void	exit_pipex(t_pipex *pipex_data, int status)
{
	int	i;

	if (pipex_data->cmd_paths)
		free_str_arr(pipex_data->cmd_paths);
	if (pipex_data->cmd_args)
		free_params(pipex_data->cmd_args);
	if (pipex_data->pipe_fds)
	{
		i = 0;
		while (i < pipex_data->cmd_count - 1)
		{
			if (pipex_data->pipe_fds[i])
				free(pipex_data->pipe_fds[i]);
			i++;
		}
		free(pipex_data->pipe_fds);
	}
	unlink(TMP_FILE);
	free(pipex_data);
	exit(status);
}
