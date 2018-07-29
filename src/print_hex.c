/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:01:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:02:42 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		shame_hex(t_p *p, char *str, int *arg_len, int *res)
{
	flags_priority(p);
	DLEN = (int)ft_strlen(str);
	if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0))
		DLEN += 2;
	*arg_len = calc_arg_len_hex(p);
	*res = *arg_len + DLEN;
	p->plus = 0;
	if (p->precision > 0)
		p->zero = 0;
	else
		p->precision = 0;
	if (p->width < DLEN || p->minus)
		p->space = 0;
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
		write(1, " ", 1);
}

void		shame_hex2(t_p *p, char *str)
{
	print_precision(p->precision);
	if (p->conv_let == 'p' || (p->sharp && p->data_uns != 0
		&& p->conv_let == 'x'))
		ft_putstr("0x");
	else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X')
		ft_putstr("0X");
	if (!(p->prec_finded && p->precision == 0 && p->data_uns == 0))
		ft_putstr(str);
	print_width_hex(p->width, p);
}

void		shame_hex3(t_p *p, char *str)
{
	if (((p->sharp && p->data_uns != 0 && p->conv_let == 'x') &&
		((p->width && p->zero) || p->precision)) ||
			(p->conv_let == 'p' && (p->zero || p->precision)))
		ft_putstr("0x");
	else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X'
		&& (p->width > 0 && p->zero == 1))
		ft_putstr("0X");
	print_width_hex(p->width, p);
	print_precision(p->precision);
	if ((p->conv_let == 'p' && ((!p->zero && !p->precision)))
        || ((p->sharp && p->data_uns != 0 && p->conv_let == 'x'
        && !p->precision) && !(p->width > 0 && p->zero == 1)))
		ft_putstr("0x");
	else if (p->sharp && p->data_uns != 0 && p->conv_let == 'X'
		&& !(p->width > 0 && p->zero == 1))
		ft_putstr("0X");
	if (!(p->prec_finded && p->precision == 0 && p->data_uns == 0))
		ft_putstr(str);
}

int			print_hex_cont(t_p *p, char *str)
{
	int		arg_len;
	int		res;

	shame_hex(p, str, &arg_len, &res);
	if (p->minus)
		shame_hex2(p, str);
	else
		shame_hex3(p, str);
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
	char	*str;
	int		len;

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
