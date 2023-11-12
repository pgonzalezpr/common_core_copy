/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:21:59 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/12 16:22:04 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils_bonus.h"

t_conversion	*init_conv(void)
{
	t_conversion	*conv;

	conv = malloc(sizeof(t_conversion));
	if (!conv)
		return (NULL);
	conv->alt_form = 0;
	conv->zero_padding = 0;
	conv->left_adjusting = 0;
	conv->sign = 0;
	conv->space = 0;
	conv->min_width = 0;
	conv->precision = 0;
	conv->conv_str = NULL;
	return (conv);
}

void	free_conv(t_conversion *conv)
{
	if (!conv)
		return ;
	if (conv->conv_str)
		free(conv->conv_str);
	free(conv);
}

int	parse_conv(const char *format, t_conversion *conv)
{
    
}

int	process_conversion(const char *format, char **buffer, va_list args)
{
	t_conversion	*conv;
	char			*tmp;
	int				conv_len;

	conv = init_conv();
	if (!conv)
		return (-1);
	if (!parse_conv(format, conv))
	{
		free_conv(conv);
		return (-1);
	}
	tmp = ft_strjoin(*buffer, conv->conv_str);
	if (!tmp)
	{
		free_conv(conv);
		return (-1);
	}
	free(*buffer);
	*buffer = tmp;
	conv_len = conv->conv_len;
	free_conv(conv);
	return (ft_strlen(conv->conv_len));
}
