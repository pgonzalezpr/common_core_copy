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
	int		fd;

	pipex_data = malloc(sizeof(t_pipex));
	if (!pipex_data)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->in_fd = -1;
	pipex_data->out_fd = -1;
	fd = open(USR_INPUT_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	close(fd);
	fd = open(TMP_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	close(fd);
	pipex_data->here_doc = 0;
	pipex_data->cmd_paths = NULL;
	pipex_data->cmd_args = NULL;
	pipex_data->cmd_count = 0;
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
		// ft_printf("freeing %s\n", arr[i]);
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
	if (pipex_data->in_fd >= 0)
		close(pipex_data->in_fd);
	if (pipex_data->out_fd >= 0)
		close(pipex_data->out_fd);
	if (pipex_data->cmd_paths)
		free_str_arr(pipex_data->cmd_paths);
	if (pipex_data->cmd_args)
		free_params(pipex_data->cmd_args);
	free(pipex_data);
	unlink(TMP_FILE);
	unlink(USR_INPUT_FILE);
	exit(status);
}
