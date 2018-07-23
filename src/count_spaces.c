#include "../headers/ft_printf.h"

int			count_spaces(t_p *p)
{
	int		i;
	char	*c;
	int		count;

	count = 0;
	i = 0;
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')) && p->local)
	{
		while (p->data_uint_copy[i])
		{
			if (p->data_uint_copy[i] == 32)
				count++;
			i++;
		}
	}
	else
	{
		c = (char*)p->data_uint_copy;
		while (*c)
		{
			if (*c == 32)
				count++;
			c++;
		}

	}
	return (count);
}