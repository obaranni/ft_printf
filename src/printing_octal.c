#include "../headers/ft_printf.h"

void			forme_oct(t_p *p)
{
	if (p->size == 'z')
		p->data = any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'j')
		p->data= any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'L')
		p->data= any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data= any_octal_to_str(p, (unsigned long)p->data_uns);
	else if (p->size == 'h')
		p->data= any_octal_to_str(p, (unsigned short)p->data_uns);
	else if (p->size == 'H')
		p->data= any_octal_to_str(p, (unsigned char)p->data_uns);
	else
		p->data= any_octal_to_str(p, (unsigned int)p->data_uns);
	p->data_len = (int)ft_strlen(p->data);
}