#include "../headers/ft_printf.h"

int		letter(t_p *p)
{
    int 	arg_len;
    int 	res;

    flags_priority(p);
    if (p->width > 1)
        arg_len = p->width - 1;
    else
        arg_len = 0;
    res = arg_len;
    if (p->minus)
    {
        if (NEG)
            write(1, "-", 1);
        if (POS && p->plus)
        {
            write(1, "+", 1);
            arg_len--;
        }
        print_precision(p->precision);
        write(1, &p->conv_let, 1);
        res++;
        print_width_char(arg_len, p);
    }
    else
    {
        print_width_char(arg_len, p);
        print_precision(p->precision);

        write(1, &p->conv_let, 1);

        res++;
    }
    return (res);
}