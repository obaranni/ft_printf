#include "../headers/ft_printf.h"

int 	choose_datatype_handler(t_p *p)
{
	if (ft_strchr("id", p->conv_let))
	{
		return (sign_dec(p));
	}
}
