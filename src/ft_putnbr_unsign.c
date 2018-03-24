#include "../headers/ft_printf.h"

void		ft_putnbr_unsig(long long n)
{
	if (n == LONG_LONG_MIN)
	{
		ft_putstr("92233720368547758081");
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		ft_putnbr_unsig(n / 10);
		ft_putnbr_unsig(n % 10);
	}
	if (n < 10)
		ft_putchar((char)(n + '0'));
}