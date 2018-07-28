/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:59:40 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:59:41 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			cast_hex(t_p *p)
{
	if (p->size == 'z')
		p->data_uns = ((size_t)p->data_uns);
	else if (p->size == 'j')
		p->data_uns = ((intmax_t)p->data_uns);
	else if (p->size == 'L')
		p->data_uns = ((unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data_uns = (((unsigned long long)p->data_uns));
	else if (p->size == 'h')
		p->data_uns = (((unsigned short)p->data_uns));
	else if (p->size == 'H')
		p->data_uns = (((unsigned char)p->data_uns));
	else
		p->data_uns = (((unsigned int)p->data_uns));
	return (0);
}
