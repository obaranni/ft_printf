/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:47:46 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:48:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	shame_letter(t_p *p, int *arg_len)
{
	p->pos = 1;
	p->precision = 0;
	flags_priority(p);
	if (p->width > 1)
		*arg_len = p->width - 1;
	else
		*arg_len = 0;
}

void	shame_letter2(t_p *p)
{
	if (NEG)
		write(1, "-", 1);
	if (POS && p->plus)
		write(1, "+", 1);
}

int		letter(t_p *p)
{
	int		arg_len;
	int		res;

	shame_letter(p, &arg_len);
	res = arg_len;
	if (p->minus)
	{
		shame_letter2(p);
		print_precision(p->precision);
		write(1, &p->conv_let, 1);
		res++;
		print_width_char(arg_len, p);
	}
	else
	{
		print_width_char(arg_len, p);
		print_precision(p->precision);
		write(1, &p->conv_let, 1);
		res++;
	}
	return (res);
}
