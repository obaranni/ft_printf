#include "../headers/ft_printf.h"

int		int_to_unsign_dec(t_p *p)
{
	int 	arg_len;
	int 	res;

    if (p->conv_let == 'U')
        p->size = 'z';
	find_usig_digit_len(p);
	flags_priority(p);
	arg_len = calc_arg_len(p);
	res = arg_len + DLEN;
	p->plus = 0;
	if (p->precision > 0)
		p->zero = 0;
	p->precision -= DLEN;
	if (p->precision > 0)
	{
		p->width -= p->precision;
		arg_len -= p->precision;
	}
	if (p->width < DLEN || p->minus)
		p->space = 0;
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		arg_len--;
	}
	if (p->minus)
	{
		print_precision(p->precision);
		print_usig_dec(p);
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		print_usig_dec(p);
	}
	return (res);
}