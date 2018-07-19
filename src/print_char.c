#include "../headers/ft_printf.h"

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
	if (!p->data_uns)
		p->precision = 0;
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