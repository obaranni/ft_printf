#include "../headers/ft_printf.h"

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
	y = (unsigned char *)p->data_uint;
	i = 0;
	while (*y)
	{
		p->data_uint_copy[i] = *y;
		i++;
		y++;
	}
}

void		which_string(t_p *p)
{
//	if (p->conv_let == 's' && !p->size)
//		str_preparation(p);
//	else
		dup_arr(&p->data_uint, &p->data_uint_copy);
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
        DLEN = count_uni_string_len(&p->data_uint_copy);
	else
	{
		int i;
		i=0;

		while (p->data_uint_copy[i])
			i++;
        DLEN = i;
	}
}

int 		print_any_string(t_p *p)
{
	if (!p->data_uint && !p->width)
	{
		ft_putstr("(null)");
		return ((int) ft_strlen("(null)"));
	}
	else
    {
        int res;
        flags_priority(p);
        if (p->data_uint)
            which_string(p);
        if (!p->precision && p->prec_finded)
            p->precision = 0;
        else if (!p->precision || DLEN <= p->precision)
            p->precision = p->data_len;
        else if (DLEN > p->precision)
        {
            int new_prec = 0;
            int i = 0;

            while (p->data_uint_copy[i])
            {
                if (count_uni_char_len(p->data_uint_copy[i]) + new_prec > p->precision)
                    break ;
                else
                    new_prec += count_uni_char_len(p->data_uint_copy[i]);
                i++;
            }
            p->precision = new_prec;
        }
        if (p->width && p->precision)
            p->width -= p->precision;
		if (p->width < 0)
			p->width = 0;
		if (p->data_uint_copy)
			res = p->width + p->precision;
		else
			res = p->width;
		if (p->minus)
		{
            if (p->data_uint_copy)
			    printing_any_str(p);
			print_width_str(p);
		}
		else
		{
			print_width_str(p);
            if (p->data_uint_copy)
                printing_any_str(p);
		}
		return (res);
	}
}