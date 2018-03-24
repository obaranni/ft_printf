#include "../headers/ft_printf.h"


int				print_data(t_p *p)
{
	long long int	digit;
	char		*data;

	digit = (long long int)p->data;

	if (p->size == 'z')
		data = long_long_toa((size_t)digit);
	else if (p->size == 'j')
		data = long_long_toa((intmax_t)digit);
	else if (p->size == 'L')
		data = long_long_toa(digit);
	else if (p->size == 'l')
		data = long_long_toa((long)digit);
	else if (p->size == 'h')
		data = long_long_toa((short)digit);
	else if (p->size == 'H')
		data = long_long_toa((char)digit);
	else
		data = long_long_toa((int)digit);

	if (data[0] == '-')
	{
		ft_putstr(++data);
		data--;
	}
	else
		ft_putstr(data);
	free(data);
	return (0);
}