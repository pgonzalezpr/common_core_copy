/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:19:13 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:14 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	trim_args(char **args)
{
	int		i;
	char	*argument;

	i = 0;
	while (args[i] != NULL)
	{
		argument = args[i];
		if (ft_strlen(argument) >= 2 && argument[0] == '\''
			&& argument[ft_strlen(argument) - 1] == '\'')
		{
			args[i] = ft_strtrim(argument, "'");
			if (args[i] == NULL)
			{
				free(argument);
				free_str_arr(args);
				return (0);
			}
			free(argument);
		}
		i++;
	}
	return (1);
}

void	parse_args(char **argv, int argc, t_pipex *pipex_data)
{
	int		i;
	char	**args;
	char	***cmd_args;

	cmd_args = ft_calloc((pipex_data->cmd_count + 1), sizeof(char **));
	if (!cmd_args)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->cmd_args = cmd_args;
	i = 2 + pipex_data->here_doc;
	while (i < argc - 1)
	{
		args = ft_shell_split(argv[i], ' ');
		if (!args)
			exit_pipex(pipex_data, EXIT_FAILURE);
		if (!trim_args(args))
			exit_pipex(pipex_data, EXIT_FAILURE);
		i++;
		*cmd_args = args;
		cmd_args++;
	}
	*cmd_args = NULL;
}
