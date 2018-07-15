#include "../headers/ft_printf.h"

int					print_sig_dec(t_p *p)
{
    p->data = 0;
	if (p->size == 'z')
		p->data = any_signed_dec_to_str(p->data_sig);
	else if (p->size == 'j')
		p->data = any_signed_dec_to_str((intmax_t)p->data_sig);
	else if (p->size == 'L')
		p->data = any_signed_dec_to_str(p->data_sig);
	else if (p->size == 'l')
		p->data = any_signed_dec_to_str((long)p->data_sig);
	else if (p->size == 'h')
		p->data = any_signed_dec_to_str((short)p->data_sig);
	else if (p->size == 'H')
		p->data = any_signed_dec_to_str((char)p->data_sig);
	else
		p->data = any_signed_dec_to_str((int)p->data_sig);

	ft_putstr(p->data);
//    if (p->data)
//        free(p->data);
	return (0);
}