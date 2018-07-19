#include "../headers/ft_printf.h"

int		print_uni_char(t_p *p)
{
	unsigned int *c;
	int arg_len;
	int res;


	if (p->data_uni_char == 0)
	{
		write(1, "", 1);
		return (1);
	}
	c = (unsigned int *)malloc(sizeof(unsigned int) * 2);
	c[0] = p->data_uni_char;
	c[1] = 0;
	flags_priority(p);
	if (p->width > 1)
		arg_len = p->width - 1;
	else
		arg_len = 0;
	res = arg_len;
	p->plus = 0;
	masks(c);
	if (p->minus)
	{
		print_precision(p->precision);
		printing_unicode(c);
		res += count_uni_string_len(&c);
		print_width_char(arg_len, p);
	}
	else
	{
		print_width_char(arg_len, p);
		print_precision(p->precision);
		printing_unicode(c);
		res += count_uni_string_len(&c);
	}
	free(c);
	return (res);
}