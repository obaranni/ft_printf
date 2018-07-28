/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_usig_dec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:47:36 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:47:57 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int				printing_usig_dec(t_p *p)
{
	if (p->size == 'z')
		p->data = any_unsigned_dec_to_str((unsigned long long)p->data_uns);
	else if (p->size == 'j')
		p->data = any_unsigned_dec_to_str((unsigned long long)p->data_uns);
	else if (p->size == 'L')
		p->data = any_unsigned_dec_to_str((unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data = any_unsigned_dec_to_str((unsigned long long)p->data_uns);
	else if (p->size == 'h')
		p->data = any_unsigned_dec_to_str((unsigned short)p->data_uns);
	else if (p->size == 'H')
		p->data = any_unsigned_dec_to_str((unsigned char)p->data_uns);
	else
		p->data = any_unsigned_dec_to_str((unsigned int)p->data_uns);
	ft_putstr(p->data);
	free(p->data);
	return (0);
}
