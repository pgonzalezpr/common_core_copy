#ifndef UTILS_H
# define UTILS_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	handle_int(int nbr);
int	putnbr_base(unsigned long nbr, char *base);
int	handle_string(char *s);
int	handle_pointer(void *ptr);
int	convert(const char conv, va_list args);

#endif // UTILS_H
