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

	len = 0;
	if (p->width > DLEN)
		len = p->width - DLEN;
	else if (p->precision > 0 && p->precision > p->width)
		len = p->precision - DLEN;
	return (len);
}

int 		print_hex(t_p *p, char *str)
{
	int 	arg_len;
	int 	res;

	flags_priority(p);
	p->data_len = (int)ft_strlen(str); //
	if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0))
		p->data_len += 2;
	arg_len = calc_arg_len_hex(p);
	if (arg_len < 0)//
		arg_len = 0;//
	res = arg_len + DLEN;
	p->plus = 0;
	if (p->precision > 0)
		p->zero = 0;
    if (p->precision > DLEN)
	    p->precision -= DLEN;
    else
        p->precision = 0;
	if (p->precision > 0)
	{
		p->width -= p->precision;
		arg_len -= p->precision;
	}
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
		print_width_hex(arg_len, p);
	}
	else
	{
		if ((p->sharp && p->data_uns != 0 && p->conv_let == 'x') && (p->width - p->data_len > 0 && p->zero == 1))
			ft_putstr("0x");
		else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X' && (p->width - p->data_len > 0 && p->zero == 1))
			ft_putstr("0X");
		print_width_hex(arg_len, p);
		print_precision(p->precision);
		if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0 && p->conv_let == 'x') && !(p->width - p->data_len > 0 && p->zero == 1))
			ft_putstr("0x");
		else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X' && !(p->width - p->data_len > 0 && p->zero == 1))
			ft_putstr("0X");
        if (!(p->prec_finded && p->precision == 0 && p->data_uns == 0))
		    ft_putstr(str);
	}
//    printf("\n%d  %d  %lu\n", p->width, p->precision, p->data_uns);
    if (!p->data_uns && p->prec_finded && !p->precision && p->width)
    {
        write(1, " ", 1);
        res += 1;
    }
    if (p->prec_finded && p->precision == 0 && p->data_uns == 0)
        return (res - 1);
	return (res);
}

int			hex(t_p *p)
{
	char 	*str;
	int 	len;

	str = 0;
	if (p->conv_let != 'p')
		cast_hex(p);
;	if (p->conv_let == 'X')
		str = itoa_base_sized(p->data_uns, 16, 'A' - 10);
	else
		str = itoa_base_sized(p->data_uns, 16, 'a' - 10);
	len = print_hex(p, str);
	if (str)
		free(str);
	return (len);
}