#include "../headers/ft_printf.h"

void		printing_any_str(t_p *p)
{
    int 	i;
    int     printed_b;
    char 	c;

    i = 0;
    printed_b = 0;
    if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
    {
        while ((printed_b < p->precision && i < p->precision && p->data_uint_copy[i]) || (printed_b < p->precision && p->data_uint_copy[i] && !p->precision && !p->prec_finded))
        {
            printed_b += count_uni_char_len(p->data_uint_copy[i]);
            if (printed_b <= p->precision)
            {
                masks(&p->data_uint_copy[i]);
                printing_unicode(&p->data_uint_copy[i]);
            }
            i++;
        }
    }
    else
    {
        while ((printed_b < p->precision && i < p->precision && p->data_uint_copy[i]) || (p->data_uint_copy[i] && !p->precision && !p->prec_finded))
        {
            c = (char)(p->data_uint_copy[i] & 0x000000FF);
            write(1, &c, 1);
            printed_b += count_uni_char_len(p->data_uint_copy[i] & 0x000000FF);
            i++;
        }
    }
    if (p->data_uint_copy[0])
        free(p->data_uint_copy);
}