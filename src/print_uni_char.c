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

	c = (unsigned int *)malloc(sizeof(unsigned int) * 2);
	c[0] = p->data_uni_char;
	c[1] = 0;

	if (p->width > 1)
	{
		p->width = p->width - count_uni_string_len(&c);
	}
	arg_len = p->width;
	res = arg_len + count_uni_string_len(&c);
	masks(c);




	if (p->minus)
	{
		print_precision(p->precision);
		printing_unicode(c);
		print_width_char(arg_len, p);
	}
	else
	{
		print_width_char(arg_len, p);
		print_precision(p->precision);
		printing_unicode(c);
	}
	free(c);
	return (res);
}