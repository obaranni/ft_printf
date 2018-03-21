#include "../headers/ft_printf.h"

void		ft_putnbr_unsig(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
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