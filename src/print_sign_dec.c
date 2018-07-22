#include "../headers/ft_printf.h"

int		int_to_sign_dec(t_p *p)
{
	int 	arg_len;
	int 	res;

	flags_priority(p);
	init_sign(p);
	if (p->minus && NEG)
		p->space = 0;
	find_sig_digit_len(p);
	arg_len = calc_arg_len(p);
	res = arg_len + p->data_len;
	if (p->plus && NEG && !p->width)
		res--;
	if ((NEG && p->width < p->data_len) ||
			(p->space && p->width <= p->data_len))
		res++;
	if (p->precision > 0)
		p->zero = 0;
	p->precision -= DLEN;
	if (p->precision > 0)
	{
		p->width -= p->precision;
		arg_len -= p->precision;
	}
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		arg_len--;
	}

	if (p->plus && !p->width)
		res++;

	if (p->minus)
	{
		if (NEG)
			write(1, "-", 1);
		if (POS && p->plus)
		{
			write(1, "+", 1);
			arg_len--;
		}
		print_precision(p->precision);
		printing_sig_dec(p);
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		printing_sig_dec(p);
	}
//	if (p->space && !p->minus)
//		res--;
	return (res);
}