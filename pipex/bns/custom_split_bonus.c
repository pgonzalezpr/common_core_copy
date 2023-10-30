/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:45:26 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/29 16:45:27 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	move_pointer_quote(char const *str, char c)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '\'' && (str[i + 1] == c || str[i + 1] == '\0'))
			return (i + 1);
		i++;
	}
	return (0);
}

int	word_split_len(char const *str, char c)
{
	int	len;

	len = 0;
	if (*str == '\'')
	{
		len = move_pointer_quote(str, c);
		if (len > 0)
			return (len);
	}
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

int	count_words(char const *str, char c)
{
	int	count;
	int	searching;

	count = 0;
	searching = 1;
	while (*str)
	{
		if (searching && *str == '\'' && move_pointer_quote(str, c) > 0)
		{
			str += move_pointer_quote(str, c);
			count++;
		}
		if (*str == '\0')
			break ;
		if (searching && *str != c)
		{
			count++;
			searching = 0;
		}
		if (*str == c)
			searching = 1;
		str++;
	}
	return (count);
}

static char	**fill_word_arr(char const *s, char **word_arr, char c)
{
	int		offset;
	char	*word;
	int		len;

	offset = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_split_len(s, c);
			word = malloc((len + 1) * sizeof(char));
			if (!word)
				return (NULL);
			ft_strlcpy(word, s, len + 1);
			word_arr[offset++] = word;
			s += len;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	word_arr[offset] = NULL;
	return (word_arr);
}

char	**ft_shell_split(char const *s, char c)
{
	char	**word_arr;
	int		words;

	words = count_words(s, c);
	word_arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	return (fill_word_arr(s, word_arr, c));
}
