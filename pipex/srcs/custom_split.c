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

static int	word_split_len(char const *str, char c)
{
    int len = 0;
    int in_quotes = 0;

    while (*str)
    {
        if (*str == '\'' && !in_quotes)
            in_quotes = 1;
        else if (*str == '\'' && in_quotes)
            in_quotes = 0;
        else if (*str != c || in_quotes)
            len++;
        if (*str == c && !in_quotes)
            break;
        str++;
    }
    return len;
}

static int count_words(char const *str, char c)
{
    int count = 0;
    int in_quotes = 0;

    while (*str)
    {
        if (*str == '\'' && !in_quotes)
            in_quotes = 1;
        else if (*str == '\'' && in_quotes)
            in_quotes = 0;
        if (!in_quotes && *str != c)
        {
            count++;
            in_quotes = 1;
        }
        str++;
    }
    if (in_quotes)
    {
        ft_printf("Error. Close quotes\n");
        return (-1);
    }
    return count;
}

static char **fill_word_arr(char const *s, char **word_arr, char c)
{
    int		offset;
	int		searching;
	char	*word;
    int     in_quotes;

    offset = 0;
	searching = 1;
    in_quotes = 0;
    while (*s)
    {
        if (*s == '\'' && !in_quotes)
        {
            in_quotes = 1;
        }
        else if (*s == '\'' && in_quotes)
        {
            in_quotes = 0;
        }
        if (!in_quotes && *s != c)
        {
            in_quotes = 1;
        }
        s++;
    }
    word_arr[offset] = NULL;
	return (word_arr);
}

char    **ft_shell_split(char const *s, char c)
{
    char	**word_arr;
    int     words;

    words = count_words(s, c);
    if (count_words == -1)
        return (NULL);
	word_arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	return (fill_word_arr(s, word_arr, c));
}
