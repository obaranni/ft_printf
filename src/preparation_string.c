/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:38:10 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/29 18:38:54 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

unsigned char		*duplicate_for_s(t_p *p)
{
	unsigned char	*newstr;
	unsigned int	*copy;

	dup_arr(&p->data_uint, &copy);
	newstr = (unsigned char*)ft_strdup((char*)copy);
	free(copy);
	return (newstr);
}

void				str_preparation(t_p *p)
{
	unsigned char	*y;
	unsigned char	*box;
	int				i;

	i = 0;
	y = duplicate_for_s(p);
	box = y;
	while (*y)
	{
		y++;
		i++;
	}
	y = box;
	p->data_uint_copy =
		(unsigned int *)malloc(sizeof(unsigned int) * i + 1);
	i = 0;
	while (*y)
	{
		p->data_uint_copy[i] = *y;
		i++;
		y++;
	}
	p->data_uint_copy[i] = 0;
	free(box);
}

void				which_string(t_p *p)
{
	int				i;

	if (p->conv_let == 's' && !p->size)
		str_preparation(p);
	else
		dup_arr(&p->data_uint, &p->data_uint_copy);
	if ((p->conv_let == 'S' || (p->conv_let == 's' && p->size == 'l')))
		DLEN = count_uni_string_len(&p->data_uint_copy);
	else
	{
		i = 0;
		while (p->data_uint_copy[i])
			i++;
		DLEN = i;
	}
}
