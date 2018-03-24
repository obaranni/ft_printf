#include "../headers/ft_printf.h"

int 		fetch_data(va_list *l, t_p *p)
{
	p->data = va_arg(*l, void *);
	return (0);
}