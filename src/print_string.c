#include "../headers/ft_printf.h"


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