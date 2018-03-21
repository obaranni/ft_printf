#include "../headers/ft_printf.h"

void		print_width(int arg_len, t_p *p)
{
	if ((int)(p->data) < 0 && p->zero)
	{
		write(1, "-", 1);
		arg_len--;
	}
	else if ((int)(p->data) < 0 && !p->zero)
		arg_len--;
	if ((int)(p->data) > 0 && !p->zero && !p->minus && (p->precision > 0 || p->plus))
		arg_len--;
	if ((int)(p->data) > 0 && p->plus && !p->minus && p->zero && p->precision <= 0)
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
	if ((int)(p->data) < 0 && !p->zero && !p->minus)
		write(1, "-", 1);
	if (((int)(p->data) > 0 && !p->zero && !p->minus && p->plus) || (p->precision > 0 && p->plus && p->zero))
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

int		sign_int_dec(t_p *p)
{
	int 	digit;
	int 	arg_len;

	digit = (int)(p->data);
	flags_priority(p, digit);
	arg_len = calc_arg_len(digit, p);
	if (p->width == 11)
		printf("");
	if (p->precision > 0)
		p->zero = 0;
	p->precision -= digit_len(digit);
	if (p->precision > 0)
	{
		p->width -= p->precision;
		arg_len -= p->precision;
	}
	if ((p->space && p->width < digit_len(digit))
		|| (p->space && p->minus && digit_len(digit)))
	{
		write(1, " ", 1);
		arg_len--;
	}
	if (p->minus)
	{
		if (digit < 0)
			write(1, "-", 1);
		if (digit > 0 && p->plus)
		{
			write(1, "+", 1);
			arg_len--;
		}
		print_precision(p->precision);
		ft_putnbr_unsig(digit);
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		ft_putnbr_unsig(digit);
	}
	return (arg_len + digit_len(digit));
}