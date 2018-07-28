/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:43:34 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:44:27 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void			forme_oct(t_p *p)
{
	if (p->size == 'z')
		p->data = any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'j')
		p->data = any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'L')
		p->data = any_octal_to_str(p, (unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data = any_octal_to_str(p, (unsigned long)p->data_uns);
	else if (p->size == 'h')
		p->data = any_octal_to_str(p, (unsigned short)p->data_uns);
	else if (p->size == 'H')
		p->data = any_octal_to_str(p, (unsigned char)p->data_uns);
	else
		p->data = any_octal_to_str(p, (unsigned int)p->data_uns);
	p->data_len = (int)ft_strlen(p->data);
}
