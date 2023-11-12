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

int	add_char(char **buffer, char c)
{
	char	c_string[2];
	char	*new_buff;

	c_string[0] = c;
	c_string[1] = '\0';
	new_buff = ft_strjoin(*buffer, c_string);
	if (!new_buff)
		return (0);
	free(*buffer);
	*buffer = new_buff;
	return (1);
}

int	process_format(const char *format, va_list args, char **buffer)
{
	int	conv_len;

	while (*format)
	{
		if (*format != '%')
		{
			if (!add_char(buffer, *format))
				return (0);
			format++;
		}
		if (*format == '%')
		{
			conv_len = process_conversion(++format, buffer, args);
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
