/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_argument_lenth.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:34:30 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:34:31 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		calc_arg_len_hex(t_p *p)
{
	int len;
	int data_len;

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

int		calc_arg_len(t_p *p)
{
	int len;

	len = 0;
	if (p->width > DLEN)
	{
		len = p->width;
		if (p->data_sig)
			len -= DLEN;
	}
	if (p->precision > 0 && p->precision > p->width
			&& p->precision > DLEN)
	{
		len = p->precision;
		if (p->data_sig)
			len -= DLEN;
	}
	return (len);
}
