#include "../headers/ft_printf.h"

int            strings(t_p *p)
{
	if (!p->data)
	{
		ft_putstr("(null)");
		return ((int) ft_strlen("(null)"));
	}
	else
	{
		ft_putstr(p->data);
		return ((int) ft_strlen(p->data));
	}
}