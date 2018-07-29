/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:34:37 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/29 18:34:51 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		any_str_shame(t_p *p)
{
	int		i;
	int		printed_b;

	i = 0;
	printed_b = 0;
	while ((printed_b < p->precision && i < p->precision
		&& p->data_uint_copy[i]) || (printed_b <
		p->precision && p->data_uint_copy[i] &&
			!p->precision && !p->prec_finded))
	{
		printed_b +=
			count_uni_char_len(p->data_uint_copy[i]);
		if (printed_b <= p->precision)
		{
			masks(&p->data_uint_copy[i]);
			printing_unicode(&p->data_uint_copy[i]);
		}
		i++;
	}
}

void		any_str_shame2(t_p *p)
{
	char	c;
	int		i;
	int		printed_b;

	i = 0;
	printed_b = 0;
	while ((printed_b < p->precision && i < p->precision
		&& p->data_uint_copy[i]) || (p->data_uint_copy[i]
		&& !p->precision && !p->prec_finded))
	{
		c = (char)(p->data_uint_copy[i] & 0x000000FF);
		write(1, &c, 1);
		printed_b++;
		i++;
	}
}

void		printing_any_str(t_p *p)
{
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
		any_str_shame(p);
	else
		any_str_shame2(p);
	if (p->data_uint_copy[0])
		free(p->data_uint_copy);
}
