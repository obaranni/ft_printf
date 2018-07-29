/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_uni_string_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:33:44 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/29 18:33:45 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int					count_uni_char_len(unsigned int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

int					count_uni_string_len(unsigned int **arr)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while ((*arr)[i])
	{
		len += count_uni_char_len((*arr)[i]);
		i++;
	}
	return (len);
}
