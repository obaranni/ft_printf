#include "../headers/ft_printf.h"

int 		fetch_data(va_list *l, t_p *p)
{
	p->data = va_arg(*l, void *);

	if (ft_strchr("id", p->conv_let))
		return (sign_int_dec(p));
}