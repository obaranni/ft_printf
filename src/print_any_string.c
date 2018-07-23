#include "../headers/ft_printf.h"

void			print_width_str(t_p *p)
{
	int 		arg_len;

	arg_len = p->width;
	while (arg_len > 0)
	{
		if (p->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		arg_len--;
	}
}

void				str_preparation(t_p *p)
{
	unsigned char	*y;
	int 			i;

	i = 0;
	y = (unsigned char *)p->data_uint;
	while (*y)
	{
		y++;
		i++;
	}
	p->data_uint_copy = (unsigned int *)malloc(sizeof(unsigned int) * i);
	p->data_uint_copy[i] = 0;
	y = (unsigned char *)p->data_uint;
	i = 0;
	while (*y)
	{
		p->data_uint_copy[i] = *y;
		i++;
		y++;
	}
}

void		printing_any_str(t_p *p)
{
	int 	i;
	char 	c;

	i = 0;
	p->local = 1; //////////////
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')) && p->local)
	{
		while ((i < p->precision && p->data_uint_copy[i]) || (p->data_uint_copy[i] && !p->precision))
		{
			masks(&p->data_uint_copy[i]);
			printing_unicode(&p->data_uint_copy[i]);
			i++;
		}
	}
	else
	{
		while ((i < p->precision && p->data_uint_copy[i]) || (p->data_uint_copy[i] && !p->precision))
		{
			c = (char)(p->data_uint_copy[i] & 0x000000FF);
			write(1, &c, 1);
			i++;
		}
	}
	free(p->data_uint_copy);
}

void		which_string(t_p *p)
{
	if (p->conv_let == 's' && !p->size)
		str_preparation(p);
	else
		dup_arr(&p->data_uint, &p->data_uint_copy);
	p->data_len = count_uni_string_len(&p->data_uint_copy);
}

int 		print_any_string(t_p *p)
{
	if (!p->data_uint)
	{
		ft_putstr("(null)");
		return ((int) ft_strlen("(null)"));
	}
	else
	{
		int res;
		int i;

		flags_priority(p);
		which_string(p);

		if (p->precision > p->data_len)
			res = p->data_len + p->width;
		else if (p->precision && p->precision < p->data_len)
			res = p->precision + p->width;
		else
			res = p->data_len + p->width;

		if (p->width && p->precision && p->data_uint_copy[0])
		{
			p->width -= p->precision;
			res -= p->precision;
			if (p->width < 0)
				p->width = 0;
		}

		p->pos = 1;
		if (p->width && p->data_uint_copy[0] && !p->precision)
		{
			p->width -= 4;
			res -= 4;
		}
		///////////////////////////// width = width - numbOfSpacesInString
		i = 0;
		if (p->minus)
		{
			printing_any_str(p);
			print_width_str(p);
		}
		else
		{
			print_width_str(p);
			printing_any_str(p);
		}
		return (res);
	}
}