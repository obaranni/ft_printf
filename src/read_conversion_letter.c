#include "../headers/ft_printf.h"

int 	read_conv_letter(char ***s, t_p *p)
{
	p->conv_let = 0;
	if (ft_strchr("sSpdDioOuUxXcC", ***s))
	{
		p->conv_let = ***s;
		return (1);
	}
	else
	{
		p->conv_let = ***s;
		write(1, **s, 1);
		return (0);
	}
}