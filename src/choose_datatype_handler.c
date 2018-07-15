#include "../headers/ft_printf.h"

int 	choose_datatype_handler(t_p *p)
{

	if (ft_strchr("idD", p->conv_let))
		return (int_to_sign_dec(p));
	else if (ft_strchr("uU", p->conv_let))
		return (int_to_unsign_dec(p));
    else if (ft_strchr("s", p->conv_let))
        return (string(p));
    else if (ft_strchr("S", p->conv_let))
        return (uni_string(p));
	else if (ft_strchr("pxX", p->conv_let))
		return (hex(p));
	else if (ft_strchr("oO", p->conv_let))
		return (octal(p));
	else if (ft_strchr("cC", p->conv_let))
		return (print_char(p));
    else if (!ft_strchr("sSpdDioOuUxXcC", p->conv_let) &&
       ((((p->conv_let) >= 'A' && p->conv_let) <= 'z') || ((p->conv_let) == '%')))
        return (letter(p));
    return (0);
}
