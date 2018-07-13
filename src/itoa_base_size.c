#include "../headers/ft_printf.h"

char 			*zero()
{
	char 		*str;
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char			*itoa_base(size_t n, int base, int size)
{
	char 		*res;
	size_t  	tmp;
	int 		i;

	i = 0;
	tmp = n;
	while (tmp)
	{
		tmp = tmp / base;
		i++;
	}
	if (n == 0)
		return (zero());
	if (!(res = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	res[i] = 0;
	while (--i > -1)
	{
		if (n % base > 9)
			res[i] = (char)((n % base) + size);
		else
			res[i] = (char)(((n % base) + 48));
		n = n / base;
	}
	return (res);
}