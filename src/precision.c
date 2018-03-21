#include "../headers/ft_printf.h"

int 		read_precision(char ***s, t_p *p)
{
	p->precision = 0;
	if (***s == '.')
	{
		p->precision = ft_atoi(++(**s));
		while (ft_isdigit(***s))
			(**s)++;
	}
	return (0);
}