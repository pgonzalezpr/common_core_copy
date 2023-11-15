/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:12:35 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/12 12:12:37 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils_bonus.h"

int	handle_non_conversion(const char *format, char **buffer)
{
	int		count;
	char	*start;
	char	*arr;
	char	*join;

	count = 0;
	start = (char *)format;
	while (*format && *format != '%')
	{
		format++;
		count++;
	}
	arr = malloc((count + 1) * sizeof(char));
	if (!arr)
		return (-1);
	ft_strlcpy(arr, start, count + 1);
	join = ft_strjoin(*buffer, arr);
	free(arr);
	if (!join)
		return (-1);
	free(*buffer);
	*buffer = join;
	return (count);
}

int	process_format(const char *format, va_list args, char **buffer)
{
	int	conv_len;
	int	non_conv_len;

	while (*format)
	{
		if (*format != '%')
		{
			non_conv_len = handle_non_conversion(format, buffer);
			if (non_conv_len == -1)
				return (0);
			format += non_conv_len;
		}
		if (*format == '%')
		{
			conv_len = handle_conversion(++format, buffer, args);
			if (conv_len == -1)
				return (0);
			format += conv_len;
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	size;
	char	*buffer;

	va_start(args, format);
	buffer = ft_strdup("");
	if (!buffer)
		return (-1);
	if (!process_format(format, args, &buffer))
	{
		free(buffer);
		return (-1);
	}
	va_end(args);
	size = ft_strlen(buffer);
	if (write(1, buffer, size) == -1)
	{
		free(buffer);
		return (-1);
	}
	free(buffer);
	return (size);
}
