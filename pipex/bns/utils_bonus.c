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

void	print_str_arr(char **arr)
{
	int	i;

	if (!arr)
		ft_printf("NULL\n");
	else
	{
		i = 0;
		while (arr[i])
		{
			ft_printf("%s ", arr[i]);
			i++;
		}
		ft_printf("\n");
	}
}

void	free_str_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	ft_printf("Array to free: ");
	print_str_arr(arr);
	while (arr[i])
	{
		ft_printf("freeing %s, (%p)\n", arr[i], &arr[i]);
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
	if (pipex_data->in_fd >= 0)
		close(pipex_data->in_fd);
	if (pipex_data->out_fd >= 0)
		close(pipex_data->out_fd);
	ft_printf("cmd count: %d\n", pipex_data->cmd_count);
	if (pipex_data->cmd_paths)
		free_str_arr(pipex_data->cmd_paths);
	if (pipex_data->cmd_args)
		free_params(pipex_data->cmd_args);
	free(pipex_data);
	unlink(TMP_FILE);
	unlink(USR_INPUT_FILE);
	exit(status);
}
