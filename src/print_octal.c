/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:05:24 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:05:30 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		shame_octal(t_p *p, int *res)
{
	p->pos = 1;
	p->plus = 0;
	flags_priority(p);
	forme_oct(p);
	*res = p->data_len;
	if (p->precision > 0)
		p->precision = p->precision - p->data_len;
	if (p->sharp && !p->precision && p->data_uns)
		p->precision++;
	else if (p->sharp && !p->precision && p->data_uns)
		p->precision = 1;
	if (p->precision > 0)
	{
		*res += p->precision;
		p->width -= p->precision;
	}
	if (p->width && p->data_uns)
		p->width -= p->data_len;
	if (p->width > 0)
		*res += p->width;
}

int			print_octal(t_p *p)
{
	int		res;

	shame_octal(p, &res);
	if (p->minus)
	{
		print_precision(p->precision);
		if (!(!p->data_uns && p->prec_finded) || p->sharp)
			ft_putstr(p->data);
		else
			res--;
		print_width(p->width, p);
	}
	else
	{
		print_width(p->width, p);
		print_precision(p->precision);
		if (!(!p->data_uns && p->prec_finded) || p->sharp)
			ft_putstr(p->data);
		else
			res--;
	}
	if (p->data)
		free(p->data);
	return (res);
}
