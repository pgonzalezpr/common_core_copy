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

/*
int	count_args(char **tokens)
{
	int	count;

	count = 0;
	while (*tokens)
	{
		if ((*tokens[0] == '-') && (ft_strlen(*tokens) > 1))
			count += ft_strlen(*tokens) - 1;
		else
			count += 1;
		tokens++;
	}
	return (count);
}

int	process_token(char *token, char **args, int *arg_offset)
{
	char	option[3];

	option[0] = '-';
	option[2] = '\0';
	if ((token[0] == '-') & (ft_strlen(token) > 1))
	{
		token++;
		while (*token)
		{
			option[1] = *token;
			args[*arg_offset] = ft_strdup(option);
			if (!args[*arg_offset])
				return (0);
			*arg_offset += 1;
			token++;
		}
		return (1);
	}
	args[*arg_offset] = ft_strdup(token);
	if (!args[*arg_offset])
		return (0);
	*arg_offset += 1;
	return (1);
}

char	**get_tokens_args(char **tokens)
{
	int		arg_offset;
	int		arg_count;
	char	**args;

	arg_count = count_args(tokens);
	args = malloc((arg_count + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	arg_offset = 0;
	while (tokens && arg_offset < arg_count)
	{
		if (!process_token(*tokens, args, &arg_offset))
		{
			free_str_arr(args);
			return (NULL);
		}
		tokens++;
	}
	args[arg_count] = NULL;
	return (args);
}

char	**get_cmd_args(char *cmd)
{
	char	**tokens;
	char	**args;

	tokens = ft_split(cmd, ' ');
	if (!tokens)
		return (NULL);
	if (*tokens == NULL)
	{
		free_str_arr(tokens);
		return (NULL);
	}
	args = get_tokens_args(tokens);
	if (!args)
	{
		free_str_arr(tokens);
		return (NULL);
	}
	free_str_arr(tokens);
	return (args);
}
*/

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

	cmd_args = malloc((pipex_data->cmd_count + 1) * sizeof(char **));
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
