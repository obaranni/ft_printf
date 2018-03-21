#include "../headers/ft_printf.h"

int		calc_arg_len(int d, t_p *p)
{
	int len;

	if (p->space && !p->width)
		len = 1 + p->width - digit_len(d);
	else
		len = p->width - digit_len(d);
	return (len);
}