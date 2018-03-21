#include "../headers/ft_printf.h"

int 		read_width(char ***s, t_p *p)
{
	p->width = 0;
	if (ft_isdigit(***s))
	{
		p->width = ft_atoi(**s);
		while (ft_isdigit(***s))
			(**s)++;
	}
	return (0);
}