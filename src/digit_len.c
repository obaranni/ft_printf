#include "../headers/ft_printf.h"

int 		digit_len(int a)
{
	int 	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0 || a < 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}