#include "../headers/ft_printf.h"

int 		fetch_data(va_list *l, t_p *p)
{

    if (ft_strchr("idD", p->conv_let)) // p->conv_let == 'd' || D || i
        p->data_sig = va_arg(*l, ssize_t);
    else if (ft_strchr("uU", p->conv_let))
        p->data_uns = va_arg(*l, size_t);
    else if (ft_strchr("s", p->conv_let))
        p->data_uns = va_arg(*l, size_t);

    return (0);
}