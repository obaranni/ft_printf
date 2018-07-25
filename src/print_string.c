#include "../headers/ft_printf.h"
/*
 * 00000000 -- 0000007F: 	0xxxxxxx
 * 00000080 -- 000007FF: 	110x xxxx  10xx xxxx
 * 00000800 -- 0000FFFF: 	1110 xxxx  10xx xxxx  10xx xxxx
 * 00010000 -- 001FFFFF: 	1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx
 *
 * Cutting
 *
 * 111100110101010111101011101
 * 000000000000011111111111000
 * &
 * 000000000000010111101011000
 *
 * Adding mask part
 * 000000000000010111101011000
 * 000000000110000000000000000
 * |
 * 000000000110010111101011000
 */

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
    int     printed_b;
	char 	c;

	i = 0;
    printed_b = 0;
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
	{
		while ((printed_b <= p->precision && i < p->precision && p->data_uint_copy[i]) || (printed_b <= p->precision && p->data_uint_copy[i] && !p->precision && !p->prec_finded))
		{
            printed_b += count_uni_char_len(p->data_uint_copy[i]);
            if (printed_b  <= p->precision)
            {
                masks(&p->data_uint_copy[i]);
                printing_unicode(&p->data_uint_copy[i]);
            }
			i++;
		}
	}
	else
	{
		while ((printed_b <= p->precision && i < p->precision && p->data_uint_copy[i]) || (p->data_uint_copy[i] && !p->precision && !p->prec_finded))
		{
			c = (char)(p->data_uint_copy[i] & 0x000000FF);
			write(1, &c, 1);
            printed_b += count_uni_char_len(p->data_uint_copy[i] & 0x000000FF);
			i++;
		}
	}
//	free(p->data_uint_copy);
}

void		which_string(t_p *p)
{
	if (p->conv_let == 's' && !p->size)
		str_preparation(p);
	else
		dup_arr(&p->data_uint, &p->data_uint_copy);
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
        DLEN = count_uni_string_len(&p->data_uint_copy);
	else
	{
		int i;
		i=0;

		while (p->data_uint_copy[i])
			i++;
		p->data_len = i;
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
			p->precision = DLEN;


		if (p->data_uint_copy[0])
			p->width = p->width - p->precision;


        if (p->width)
            p->width -= p->data_len/4;
		if (p->width < 0)
			p->width = 0;

		if (p->data_uint_copy[0])
			res = p->width + p->precision;
		else
			res = p->width;
		///////////////////////////// width = width - numbOfSpacesInString
		if (p->minus)
		{
            if (p->data_uint_copy[0])
			    printing_any_str(p);
			print_width_str(p);
		}
		else
		{
			print_width_str(p);
            if (p->data_uint_copy[0])
                printing_any_str(p);
		}
		return (res);
	}
}