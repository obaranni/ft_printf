#include "../headers/ft_printf.h"

int		print_uni_char(t_p *p)
{
	unsigned int *c;
	int arg_len;
	int res;

	flags_priority(p);
	p->plus = 0;

	if (p->data_uni_char == 0)
	{
		if (p->width > 0)
			arg_len = p->width - 1;
		else
			arg_len = 0;
		print_width_char(arg_len, p);
		write(1, "", 1);
		return (arg_len + 1);
	}







	if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')) && p->local)
	{
		c = (unsigned int *)malloc(sizeof(unsigned int) * 2);
		c[0] = p->data_uni_char;
		c[1] = 0;
		if (p->width > 0)
		{
			p->width = p->width - count_uni_string_len(&c);
			if (p->width < 0)
				p->width = 0;
		}
		arg_len = p->width;
		res = arg_len + count_uni_string_len(&c);
		masks(c);
	}
	else
	{
		if (p->width > 0)
			p->width--;
		arg_len = p->width;
		res = arg_len + 1;
		c = &p->data_uni_char;
	}




	if (p->minus)
	{
		print_precision(p->precision);
		if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')) && p->local)
			printing_unicode(c);
		else
			write(1, c, 1);
		print_width_char(arg_len, p);
	}
	else
	{
		print_width_char(arg_len, p);
		print_precision(p->precision);
		if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')) && p->local)
			printing_unicode(c);
		else
			write(1, c, 1);
	}
	if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')) && p->local)
		free(c);
	return (res);
}