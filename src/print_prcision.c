#include "../headers/ft_printf.h"

int 	print_precision(int prec)
{
	int i;

	i = 0;
	while (i < prec && prec > 0)
	{
		write(1, "0", 1);
		i++;
	}
	return (0);
}
