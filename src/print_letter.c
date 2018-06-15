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
    p->plus = 0;
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
        ft_putchar(p->conv_let);
        res++;
        print_width(arg_len, p);
    }
    else
    {
        print_width(arg_len, p);
        print_precision(p->precision);
        ft_putchar(p->conv_let);
        res++;
    }
    return (res);
}