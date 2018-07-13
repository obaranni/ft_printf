#include "../headers/ft_printf.h"

void		print_width_char(int arg_len, t_p *p)
{
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
}

int		print_char(t_p *p)
{
	int 	arg_len;
	int 	res;

	flags_priority(p);
	if (p->width > 1)
		arg_len = p->width - 1;
	else
		arg_len = 0;
	res = arg_len;
	p->plus = 0;
	if (p->minus)
	{
		print_precision(p->precision);
		ft_putchar((char)p->data_uns);
		res++;
		print_width_char(arg_len, p);
	}
	else
	{
		print_width_char(arg_len, p);
		print_precision(p->precision);
		ft_putchar((char)p->data_uns);
		res++;
	}
	return (res);
}