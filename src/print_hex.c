#include "../headers/ft_printf.h"

void		print_width_hex(int arg_len, t_p *p)
{
	if (p->space && p->zero)
	{
		write(1, " ", 1);
		arg_len--;
	}
	while (arg_len > 0)
	{
		if (p->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		arg_len--;
	}
}

int 		cast_hex(t_p *p)
{
	if (p->size == 'z')
		p->data_uns = ((size_t)p->data_uns);
	else if (p->size == 'j')
		p->data_uns = ((intmax_t)p->data_uns);
	else if (p->size == 'L')
		p->data_uns = ((unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data_uns = (((unsigned long long)p->data_uns));
	else if (p->size == 'h')
		p->data_uns = (((unsigned short)p->data_uns));
	else if (p->size == 'H')
		p->data_uns = (((unsigned char)p->data_uns));
	else
		p->data_uns = (((unsigned int)p->data_uns));
	return (0);
}

int		calc_arg_len_hex(t_p *p)
{
	int len;
    int data_len;

	len = 0;

    if ((p->sharp || p->conv_let == 'p') && p->precision > DLEN - 2)
        data_len = DLEN - 2;
    else
        data_len = DLEN;

    if (p->precision)
        p->precision = p->precision - data_len;

    if (p->precision < 0)
        p->precision = 0;

	if (p->width && !p->precision)
        p->width = p->width - data_len;

    if (p->width < 0)
        p->width = 0;


    if (p->precision > 0 && p->width > 0)
        p->width -= p->precision + data_len;

    if (p->width < 0)
        p->width = 0;
    len = p->width + p->precision;
    if (len < 0)
        len = 0;
	return (len);
}

int 		print_hex_cont(t_p *p, char *str)
{
	int 	arg_len;
	int 	res;

	flags_priority(p);
	DLEN = (int)ft_strlen(str); //
	if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0))
		DLEN += 2;
	arg_len = calc_arg_len_hex(p);
	res = arg_len + DLEN;
	p->plus = 0;
	if (p->precision > 0)
		p->zero = 0;
    else
        p->precision = 0;
	if (p->width < DLEN || p->minus)
		p->space = 0;
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		arg_len--;
	}
	if (p->minus)
	{
		print_precision(p->precision);
		if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0 && p->conv_let == 'x'))
			ft_putstr("0x");
		else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X')
			ft_putstr("0X");
        if (!(p->prec_finded && p->precision == 0 && p->data_uns == 0))
            ft_putstr(str);
		print_width_hex(p->width, p);
	}
	else
	{
		if (((p->sharp && p->data_uns != 0 && p->conv_let == 'x') && ((p->width && p->zero) || p ->precision)) || (p->conv_let == 'p' && (p->zero || p->precision)))
			ft_putstr("0x");
		else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X' && (p->width > 0 && p->zero == 1))
			ft_putstr("0X");
		print_width_hex(p->width, p);
		print_precision(p->precision);
		if ((p->conv_let == 'p' && ((!p->zero && !p->precision))) || (p->sharp && p->data_uns != 0 && p->conv_let == 'x' && !p->precision) && !(p->width > 0 && p->zero == 1))
			ft_putstr("0x");
		else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X' && !(p->width > 0 && p->zero == 1))
			ft_putstr("0X");
        if (!(p->prec_finded && p->precision == 0 && p->data_uns == 0))
		    ft_putstr(str);
	}
    if (!p->data_uns && p->prec_finded && !p->precision && p->width)
    {
        write(1, " ", 1);
        res += 1;
    }
    if (p->prec_finded && p->precision == 0 && p->data_uns == 0)
        return (res - 1);
	return (res);
}

int			print_hex(t_p *p)
{
	char 	*str;
	int 	len;

	if (p->conv_let != 'p')
		cast_hex(p);
	if (p->conv_let == 'X')
		str = itoa_base_sized(p->data_uns, 16, 'A' - 10);
	else
		str = itoa_base_sized(p->data_uns, 16, 'a' - 10);
	len = print_hex_cont(p, str);
	if (str)
		free(str);
	return (len);
}