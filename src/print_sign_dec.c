#include "../headers/ft_printf.h"

int		int_to_sign_dec(t_p *p)
{
	int 	arg_len;
	int 	res;

	flags_priority(p);
	init_sign(p);
	if (NEG)
		p->space = 0;
	find_sig_digit_len(p);
	arg_len = calc_arg_len(p);
	res = arg_len + p->data_len;
	if (p->plus && NEG && !p->width)
		res--;
	if ((NEG && p->width < p->data_len) ||
			(p->space && p->width <= p->data_len) ||
			(NEG && p->width > p->data_len && p->precision
			 && p->width < p->precision))
		res++;
	if (p->precision > 0)
		p->zero = 0;
	if (p->data_sig)
		p->precision -= DLEN;



	if (p->precision > 0)
	{
		if (p->width)
			p->width -= p->precision;
		if (p->width < 0)
			p->width = 0;
		arg_len -= p->precision;
		if (!p->data_sig)
			res--;
	}


	if ((p->precision  && p->precision > p->width && p->width > 0))
		res += p->precision - p->data_len ;



	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		arg_len--;
	}

	if (p->plus && !p->width)
		res++;

	if (!p->data_sig && (p->plus || p->minus) && p->width)
	{
		res--;
		arg_len--;
	}
	if (p->data_sig && p->plus && p->width && p->width <= DLEN)
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
		if (p->data_sig || (!p->data_sig && (p->plus || p->size || p->minus)))
			printing_sig_dec(p);
		else
			res--;
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		if (p->data_sig || (!p->data_sig && (p->plus || p->size || p->minus)))
			printing_sig_dec(p);
		else
			res--;
	}
//	if (p->space && !p->minus)
//		res--;
	return (res);
}