/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:17:56 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:17:58 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*init_pipex(void)
{
	t_pipex	*pipex_data;

	pipex_data = malloc(sizeof(t_pipex));
	if (!pipex_data)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->infile = NULL;
	pipex_data->outfile = NULL;
	pipex_data->cmd_paths = NULL;
	pipex_data->cmd_args = NULL;
	return (pipex_data);
}

void	check_input(char **argv, int argc, t_pipex *pipex_data)
{
	if (argc != 5)
	{
		ft_printf(STDOUT_FILENO, "Error. Incorrect number of arguments\n");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	pipex_data->infile = argv[1];
	pipex_data->outfile = argv[4];
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

void	exit_pipex(t_pipex *pipex_data, int status)
{
	if (pipex_data->cmd_paths)
		free_str_arr(pipex_data->cmd_paths);
	if (pipex_data->cmd_args)
		free_params(pipex_data->cmd_args);
	free(pipex_data);
	exit(status);
}
