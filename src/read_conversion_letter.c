/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion_letter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:41:30 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:41:49 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		read_conv_letter(char ***s, t_p *p)
{
	p->conv_let = 0;
	if (***s && (ft_strchr("sSpdDioOuUxXcC", ***s)
		|| ((***s >= 'A' && ***s <= 'z') || (***s == '%'))))
	{
		p->conv_let = ***s;
		return (1);
	}
	return (0);
}
