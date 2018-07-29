/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:43:47 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/29 18:45:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		preparing_strings_shame(t_p *p)
{
	int new_prec;
	int i;

	i = 0;
	new_prec = 0;
	if (p->data_uint)
		which_string(p);
	if (!p->precision && p->prec_finded)
		p->precision = 0;
	else if (!p->precision || DLEN <= p->precision)
		p->precision = p->data_len;
	else if (DLEN > p->precision)
	{
		while (p->data_uint_copy[i])
		{
			if (count_uni_char_len(p->data_uint_copy[i])
					+ new_prec > p->precision)
				break ;
			else
				new_prec += count_uni_char_len(p->data_uint_copy[i]);
			i++;
		}
		p->precision = new_prec;
	}
}

int			preparing_strings(t_p *p)
{
	int		res;

	flags_priority(p);
	preparing_strings_shame(p);
	if (p->width && p->precision)
		p->width -= p->precision;
	if (p->width < 0)
		p->width = 0;
	if (p->data_uint_copy)
		res = p->width + p->precision;
	else
		res = p->width;
	if (p->minus)
	{
		if (p->data_uint_copy)
			printing_any_str(p);
		print_width_str(p);
	}
	else
	{
		print_width_str(p);
		if (p->data_uint_copy)
			printing_any_str(p);
	}
	return (res);
}

int			print_any_string(t_p *p)
{
	if (!p->data_uint && !p->width)
	{
		ft_putstr("(null)");
		return ((int) ft_strlen("(null)"));
	}
	else
		return (preparing_strings(p));
}
