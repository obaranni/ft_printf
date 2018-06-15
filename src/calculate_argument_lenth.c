#include "../headers/ft_printf.h"

int		calc_arg_len(t_p *p)
{
	int len;

	len = 0;
	if (p->width > DLEN)
		len = p->width - DLEN;
	else if (p->precision > 0 && p->precision > p->width)
		len = p->precision - DLEN;
	return (len);
}