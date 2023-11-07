/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:57 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:04 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*read_input(char *delimiter)
{
	char	*input;
	char	*tmp;
	char	*buffer;

	input = ft_strdup("");
	if (!input || !delimiter)
		return (NULL);
	buffer = get_next_line(1);
	while (buffer)
	{
		if (ft_strequals(buffer, delimiter))
		{
			free(buffer);
			break ;
		}
		tmp = input;
		input = ft_strjoin(input, buffer);
		free(tmp);
		free(buffer);
		buffer = get_next_line(1);
	}
	free(delimiter);
	return (input);
}

void	check_input(char **argv, int argc, char **envp, t_pipex *pipex_data)
{
	if (argc < 5 || (ft_strequals(argv[1], "here_doc") && argc < 6))
	{
		ft_printf(STDOUT_FILENO, "Error. Incorrect number of arguments\n");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	pipex_data->here_doc = ft_strequals(argv[1], "here_doc");
	if (pipex_data->here_doc)
		pipex_data->delimiter = argv[2];
	else
		pipex_data->infile = argv[1];
	pipex_data->envp = envp;
	pipex_data->outfile = argv[argc - 1];
	pipex_data->cmd_count = argc - 3 - pipex_data->here_doc;
	pipex_data->pipe_fds = ft_calloc(pipex_data->cmd_count - 1, sizeof(int *));
	if (!pipex_data->pipe_fds)
		exit_pipex(pipex_data, EXIT_FAILURE);
}
