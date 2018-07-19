#include "../headers/ft_printf.h"

void			printing_unicode(unsigned int *u)
{
	int 		i;
	unsigned int	f;

	i = 0;
	while (i < 4)
	{
		f = ((*u << (i * 8)) >> 24);
		if (f)
			write(1, &f, 1);
		i++;
	}
}