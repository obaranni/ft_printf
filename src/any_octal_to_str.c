/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_octal_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:37:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:37:32 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*any_octal_to_str(t_p *p, size_t nb)
{
	if (p->conv_let == 'O')
		return (itoa_base_sized(nb, 8, 55));
	else
		return (itoa_base_sized(nb, 8, 87));
}
