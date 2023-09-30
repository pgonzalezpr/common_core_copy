/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:32 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/30 13:15:34 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_utils.h"

int	check_range(char *str, int max)
{
	char	*max_str;
	int		ans;

	max_str = ft_itoa(max);
	if (ft_strlen(str) == ft_strlen(max_str))
		ans = (ft_strncmp(max_str, str, ft_strlen(max_str)) >= 0);
	else
		ans = (ft_strlen(max_str) > ft_strlen(str));
	free(max_str);
	return (ans);
}

int	is_int(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '-')
	{
		i++;
		sign = 1;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	if (sign)
		return (check_range(str, INT_MIN));
	return (check_range(str, INT_MAX));
}

int	contains(int num, int *arr, int len)
{
	while (len > 0)
	{
		if (arr[len - 1] == num)
			return (1);
		len--;
	}
	return (0);
}

int	*process_input(char **input, int len)
{
	int	*arr;
	int	i;
	int	num;

	arr = malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!is_int(input[i]))
		{
			free(arr);
			return (NULL);
		}
		num = ft_atoi(input[i]);
		if (contains(num, arr, i))
		{
			free(arr);
			return (NULL);
		}
		arr[i++] = num;
	}
	return (arr);
}
