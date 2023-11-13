/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:59 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:01 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils_bonus.h"

int	parse_flags(const char *format, t_conversion *conv)
{
	int	count;

	count = 0;
	while (ft_strchr(FLAGS, *format) != 0)
	{
		if (*format == '-')
			conv->left_adjustment = 1;
		if (*format == '0')
			conv->zero_padding = 1;
		if (*format == '#')
			conv->alt_form = 1;
		if (*format == '+')
			conv->sign = 1;
		if (*format == ' ')
			conv->space = 1;
		count++;
		format++;
	}
	conv->conv_len += count;
	return (count);
}

int	parse_width(const char *format, t_conversion *conv)
{
	int	count;
	int	width;

	count = 0;
	width = 0;
	while (ft_isdigit(*format))
	{
		width = width * 10 + (*format - '0');
		count++;
		format++;
	}
	conv->min_width = width;
	conv->conv_len += count;
	return (count);
}

int	parse_precision(const char *format, t_conversion *conv)
{
	int	count;
	int	precision;

	if (*format != '.')
		return (0);
	format++;
	count = 1;
	precision = 0;
	while (ft_isdigit(*format))
	{
		precision = precision * 10 + (*format - '0');
		count++;
		format++;
	}
	conv->precision = precision;
	conv->conv_len += count;
	return (count);
}

char	*build_conv_str(t_conversion *conv, va_list args)
{
	if (args && conv)
		return (ft_strdup("CONVERSION"));
	return (ft_strdup("CONVERSION"));
}
