#include "../headers/ft_printf.h"

char        *any_octal_to_str(t_p *p, size_t nb)
{
	if (p->conv_let == 'O')
		return (itoa_base_sized(nb, 8, 55));
	else
		return  (itoa_base_sized(nb, 8, 87));
}