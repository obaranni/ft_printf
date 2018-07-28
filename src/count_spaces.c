/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:49:24 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:50:10 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			count_spaces(t_p *p)
{
	int		i;
	char	*c;
	int		count;

	count = 0;
	i = 0;
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
	{
		while (p->data_uint_copy[i])
		{
			if (p->data_uint_copy[i++] == 32)
				count++;
		}
	}
	else
	{
		c = (char*)p->data_uint_copy;
		while (*c)
		{
			if (*c == 32)
				count++;
			c++;
		}
	}
	return (count);
}
