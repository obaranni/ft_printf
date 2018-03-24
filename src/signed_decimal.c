#include "../headers/ft_printf.h"

void		print_width(int arg_len, t_p *p)
{
	if (NEG && p->zero)
	{
		write(1, "-", 1);
		arg_len--;
	}
	else if (NEG && !p->zero)
		arg_len--;
	if (POS && !p->zero && !p->minus && (p->precision > 0 || p->plus))
		arg_len--;
	if (POS && p->plus && !p->minus && p->zero && p->precision <= 0)
	{
		write(1, "+", 1);
		arg_len--;
	}
	if (p->space && p->zero)
	{
		write(1, " ", 1);
		arg_len--;
	}
	while (arg_len > 0)
	{
		if (p->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		arg_len--;
	}
	if (NEG && !p->zero && !p->minus)
		write(1, "-", 1);
	if ((POS && !p->zero && !p->minus && p->plus) || (p->precision > 0 && p->plus && p->zero))
		write(1, "+", 1);
}

int 	print_precision(int prec)
{
	int i;

	i = 0;
	while (i < prec && prec > 0)
	{
		write(1, "0", 1);
		i++;
	}
}

int		sign_dec(t_p *p)
{
	int 	arg_len;

	init_sign(p);
	find_digit_len(p);
	flags_priority(p);
	arg_len = calc_arg_len(p);
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
		print_data(p);
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		print_data(p);
	}
	return (arg_len + DLEN);
}