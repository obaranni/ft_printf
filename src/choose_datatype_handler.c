#include "../headers/ft_printf.h"

int 	choose_datatype_handler(t_p *p)
{

	if (ft_strchr("idD", p->conv_let))
		return (int_to_sign_dec(p));
	else if (ft_strchr("uU", p->conv_let))
		return (int_to_unsign_dec(p));
    else if (ft_strchr("cCsS", p->conv_let))
        return (strings(p));
    else if (!ft_strchr("sSpdDioOuUxXcC", p->conv_let) &&
       ((((p->conv_let) >= 'A' && p->conv_let) <= 'z') || ((p->conv_let) == '%')))
        return (letter(p));
    return (0);
}
