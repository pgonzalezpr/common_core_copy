/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:07 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/09 13:27:08 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_max(char *str)
{
	int	ans;

	while (*str == '0')
		str++;
	if (*str == '\0')
		return (1);
	if (ft_strlen(str) == ft_strlen(MAX_TIME_MS))
		ans = (ft_strncmp(MAX_TIME_MS, str, ft_strlen(MAX_TIME_MS)) == 0);
	else
		ans = (ft_strlen(MAX_TIME_MS) > ft_strlen(str));
	return (ans);
}

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (0);
		if (i > 1 && i < 5 && !check_max(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
