/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:20:43 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:20:44 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	sign_dec_shame(t_p *p, int *arg_len, int *res)
{
	find_sig_digit_len(p);
	(*arg_len) = calc_arg_len(p);
	(*res) = *arg_len + p->data_len;
	if (p->plus && NEG && !p->width)
		(*res)--;
	if ((NEG && p->width < p->data_len) ||
		(p->space && p->width <= p->data_len) ||
		(NEG && p->width > p->data_len && p->precision
		&& p->width < p->precision))
		(*res)++;
	if (p->precision > 0)
		p->zero = 0;
	if (p->data_sig)
		p->precision -= DLEN;
	if (p->precision > 0)
	{
		if (p->width)
			p->width -= p->precision;
		if (p->width < 0)
			p->width = 0;
		(*arg_len) -= p->precision;
		if (!p->data_sig)
			(*res)--;
	}
}

void	sign_dec_shame2(t_p *p, int *arg_len, int *res)
{
	if ((p->precision && p->precision > p->width && p->width > 0))
		(*res) += p->precision - p->data_len;
	if ((p->space && p->width < DLEN)
		|| (p->space && p->minus && DLEN))
	{
		write(1, " ", 1);
		(*arg_len)--;
	}
	if (p->plus && !p->width)
		(*res)++;
	if (!p->data_sig && (p->plus || p->minus) && p->width)
	{
		(*res)--;
		(*arg_len)--;
	}
	if ((p->data_sig && p->plus && p->width && p->width <= DLEN) ||
		(p->space && (p->width < p->precision)))
		(*res)++;
}

void	sign_dec_shame3(t_p *p, int *arg_len, int *res)
{
	if (NEG)
		write(1, "-", 1);
	if (POS && p->plus)
	{
		write(1, "+", 1);
		(*arg_len)--;
	}
	print_precision(p->precision);
	if (p->data_sig || (!p->data_sig &&
		(p->plus || p->size || p->minus)))
		printing_sig_dec(p);
	else
		(*res)--;
	print_width(*arg_len, p);
}

int		int_to_sign_dec(t_p *p)
{
	int		arg_len;
	int		res;

	flags_priority(p);
	init_sign(p);
	if (NEG)
		p->space = 0;
	sign_dec_shame(p, &arg_len, &res);
	sign_dec_shame2(p, &arg_len, &res);
	if (p->minus)
		sign_dec_shame3(p, &arg_len, &res);
	else
	{
		print_width(arg_len, p);
		print_precision(p->precision);
		if (p->data_sig || (!p->data_sig
							&& (p->plus || p->size || p->minus)))
			printing_sig_dec(p);
		else
			res--;
	}
	return (res);
}
