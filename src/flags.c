#include "../headers/ft_printf.h"

int 		flags_priority(t_p *p)
{
	if (p->minus)
		p->zero = 0;
	if (p->plus)
		p->space = 0;
	if (p->space && !p->pos)
		p->space = 0;
	if (ft_strchr("DOU", p->conv_let))
		p->size = 'z';
	return (0);
}

int 		read_flags(char ***s, t_p *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->plus = 0;
	p->minus = 0;
	p->space = 0;
	while (***s)
	{
		if (***s == '+')
			p->plus = 1;
		else if (***s == '-')
			p->minus = 1;
		else if (***s == '#')
			p->sharp = 1;
		else if (***s == ' ')
			p->space = 1;
		else if (***s == '0')
			p->zero = 1;
		else
			return (0);
		(**s)++;
	}
	return (1);
}