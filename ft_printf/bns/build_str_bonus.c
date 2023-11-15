#include "../include/utils_bonus.h"

char	*build_nbr_base(t_conversion *conv, unsigned long nbr, char *base)
{
	char	*nbr_str;
	int		width;
	char	*buff;

	nbr_str = ft_itoa_base(nbr, base);
	if (!nbr_str)
		return (NULL);
	if (conv->specifier == 'u')
		conv->alt_form = 0;
	if (conv->specifier == 'x' || conv->specifier == 'X')
	{
		conv->sign = 0;
		conv->space = 0;
	}
    if (conv->prec != -1)
    {
        conv->zero_padding = 0;
    }
	width = conv->min_width;
	//printf("width: %d, nbr_str: %s\n", width, nbr_str);
    if (!(conv->prec == 0 && nbr == 0))
		width = get_buff_width(conv, nbr_str);
	buff = malloc((width + 1) * sizeof(char));
	if (!buff)
	{
		free(nbr_str);
		return (NULL);
	}
	fill_blanks(buff, width + 1);
	//print_conv(conv);
	fill_buff(nbr_str, buff, conv, width);
	//printf("%s\n", buff);
	free(nbr_str);
	return (buff);
}

char	*build_int(t_conversion *conv, int nbr)
{
	char	*nbr_str;
	int		width;
	char	*buff;

	nbr_str = ft_itoa(nbr);
	if (!nbr_str)
		return (NULL);
	conv->alt_form = 0;
	if (nbr < 0)
	{
		conv->sign = 0;
		conv->space = 0;
	}
    if (conv->prec != -1)
    {
        conv->zero_padding = 0;
    }
	width = conv->min_width;
    if (!(conv->prec == 0 && nbr == 0))
		width = get_buff_width(conv, nbr_str);
	buff = malloc((width + 1) * sizeof(char));
	if (!buff)
	{
		free(nbr_str);
		return (NULL);
	}
	fill_blanks(buff, width + 1);
    //printf("HEREE width: %d\n", width);
    //print_conv(conv);
	fill_buff(nbr_str, buff, conv, width);
	free(nbr_str);
	return (buff);
}

char	*build_ptr(t_conversion *conv, void *ptr)
{
	unsigned long	ptr_nbr;

	conv->alt_form = 1;
	conv->zero_padding = 0;
	conv->sign = 0;
	conv->space = 0;
    conv->prec = -1;
	conv->specifier = 'x';
    if (!ptr)
    {
        return (build_str(conv, "(nil)"));
    }
	ptr_nbr = (unsigned long)ptr;
	return (build_nbr_base(conv, ptr_nbr, HEX_LOW_BASE));
}

char	*build_char(t_conversion *conv, char c)
{
	int		width;
	char	*buff;

	width = 1;
	if (conv->min_width > width)
		width = conv->min_width;
	buff = malloc((width + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	fill_blanks(buff, width + 1);
	buff[width] = '\0';
	if (conv->left_adjustment)
		buff[0] = c;
	else
		buff[width - 1] = c;
	return (buff);
}

char	*build_str(t_conversion *conv, char *str)
{
	int		width;
	int		len;
	char	*buff;
	char	start;

    if (!str)
    {
        str = "(null)";
        if (conv->prec != -1 && conv->prec < 6)
            conv->prec = 0;
    }
	len = ft_strlen(str);
	if (conv->prec != -1 && conv->prec < len)
		len = conv->prec;
	width = len;
	if (width < conv->min_width)
		width = conv->min_width;
	buff = malloc((width + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_blanks(buff, width + 1);
	buff[width] = '\0';
	start = width - len;
	if (conv->left_adjustment)
		start = 0;
	ft_memcpy(buff + start, str, len);
	return (buff);
}
