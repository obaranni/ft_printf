#include "../headers/ft_printf.h"

int 		fetch_data(va_list *l, t_p *p)
{

    if (ft_strchr("idD", p->conv_let)) // p->conv_let == 'd' || D || i
        p->data_sig = va_arg(*l, ssize_t);
    else if (ft_strchr("uU", p->conv_let))
        p->data_uns = va_arg(*l, size_t);
    else if (ft_strchr("s", p->conv_let))
        p->data = va_arg(*l, char*);
    else if (ft_strchr("S", p->conv_let))
        p->data_uint = va_arg(*l, unsigned int*);
	else if (ft_strchr("p", p->conv_let))
		p->data_uns = va_arg(*l, size_t);
	else if (ft_strchr("xX", p->conv_let))
		p->data_uns = (size_t)va_arg(*l, size_t);
	else if (ft_strchr("oO", p->conv_let))
		p->data_uns = (size_t)va_arg(*l, size_t);
	else if (ft_strchr("cC", p->conv_let))
		p->data_uns = (size_t)va_arg(*l, unsigned char);
    return (0);
}