#include "../headers/ft_printf.h"

int		calc_arg_len(t_p *p)
{
	int len;

	if (p->space && !p->width)
		len = 1 + p->width - DLEN;
	else
		len = p->width - DLEN;
	return (len);
}