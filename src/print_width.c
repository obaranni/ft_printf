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
	if (POS && !p->zero && !p->minus && (p->precision > 0 || p->plus) && (p->plus || p->minus))
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