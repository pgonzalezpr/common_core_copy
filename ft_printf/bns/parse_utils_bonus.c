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

int     parse_flags(const char *format, t_conversion *conv)
{
    if (format && conv)
        return (0);
    return (0);
}

int     parse_width(const char *format, t_conversion *conv)
{
    if (format && conv)
        return (0);
    return (0);
}

int     parse_precision(const char *format, t_conversion *conv, va_list args)
{
    if (format && conv && args)
        return (0);
    return (0);
}

char    *build_conv_str(t_conversion *conv, va_list args)
{
    if (args && conv)
        return ("HELLO");
    return ("HELLO");
}

