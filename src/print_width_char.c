#include "../headers/ft_printf.h"

void		print_width_char(int arg_len, t_p *p)
{
    if (p->space && p->zero)
    {
        write(1, " ", 1);
        arg_len--;
    }
    while (arg_len > 0)
    {
        if (p->zero)
            write(1, "0", 1);
        else
            write(1, " ", 1);
        arg_len--;
    }
}