/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:40:46 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/17 12:21:38 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf_int(int nbr);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	ft_printf_string(char *s);
int	ft_printf_pointer(void *ptr);
int	convert(const char conv, va_list args);

#endif // UTILS_H
