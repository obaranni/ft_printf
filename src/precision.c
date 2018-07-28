/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:38:35 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:38:40 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			read_precision(char ***s, t_p *p)
{
	p->precision = 0;
	p->prec_finded = 0;
	if (***s == '.')
	{
		p->prec_finded = 1;
		p->precision = ft_atoi(++(**s));
		while (ft_isdigit(***s))
			(**s)++;
	}
	return (0);
}
