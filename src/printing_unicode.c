/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:46:09 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:46:32 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void				printing_unicode(unsigned int *u)
{
	int				i;
	unsigned int	f;
	unsigned int	box;

	i = 0;
	box = *u;
	while (i < 4)
	{
		f = ((box << (i * 8)) >> 24);
		if (f)
			write(1, &f, 1);
		i++;
	}
}
