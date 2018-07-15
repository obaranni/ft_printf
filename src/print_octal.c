#include "../headers/ft_printf.h"

int			octal(t_p *p)
{
	char 	*str;
	int 	len;

	str = 0;
	if (p->conv_let == 'O')
		str = itoa_base_sized(p->data_uns, 8, 55);
	else
		str = itoa_base_sized(p->data_uns, 8, 87);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	if (str)
		free(str);
	if (p->conv_let == 'p')
		return (len + 2);
	return (len);
}