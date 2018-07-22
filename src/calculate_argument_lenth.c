#include "../headers/ft_printf.h"

int		calc_arg_len(t_p *p)
{
	int len;

	len = 0;
	if (p->width > DLEN)
	{
		len = p->width;
		if (p->data_sig)
			len -= DLEN;
	}
	if (p->precision > 0 && p->precision > p->width && p->precision > DLEN)
	{
		len = p->precision;
		if (p->data_sig)
			len -= DLEN;
	}
	return (len);
}