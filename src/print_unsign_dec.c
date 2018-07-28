/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:24:02 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:24:04 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		unsign_dec_shame(t_p *p, int *arg_len, int *res)
{
	flags_priority(p);
	p->pos = 1;
	find_usig_digit_len(p);
	(*arg_len) = calc_arg_len(p);
	(*res) = (*arg_len) + DLEN;
	if (p->precision > 0)
		p->zero = 0;
	p->precision -= DLEN;
	if (p->precision > 0)
	{
		p->width -= p->precision;
		(*arg_len) -= p->precision;
	}
	if (p->width < DLEN || p->minus)
		p->space = 0;
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		(*arg_len)--;
	}
}

int		int_to_unsign_dec(t_p *p)
{
	int		arg_len;
	int		res;

	unsign_dec_shame(p, &arg_len, &res);
	if (p->minus)
	{
		print_precision(p->precision);
		if (p->data_uns || (!p->data_uns &&
				((!(!p->precision && p->prec_finded)) || p->size)))
			printing_usig_dec(p);
		else
			res--;
		print_width(arg_len, p);
	}
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		if (p->data_uns || (!p->data_uns &&
				(((p->precision && !p->prec_finded)) || p->size)))
			printing_usig_dec(p);
		else
			res--;
	}
	return (res);
}
