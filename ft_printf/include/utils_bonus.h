/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:12:10 by pedro-go          #+#    #+#             */
/*   Updated: 2023/11/12 16:12:11 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FLAGS "-0.# +"
# define VALID_CONV "cspdiuxX"

typedef struct s_conversion
{
	int		alt_form;
	int		zero_padding;
	int		left_adjusting;
	int		sign;
	int		space;
	int		min_width;
	int		precision;
	int		conv_len;
	char	*conv_str;
}			t_conversion;

int			process_conversion(const char *format, char **buffer, va_list args);
int			add_char(char **buffer, char c);

#endif // UTILS_BONUS_H
