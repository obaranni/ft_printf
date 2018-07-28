/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prcision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:06:27 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:06:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		print_precision(int prec)
{
	int i;

	i = 0;
	while (i < prec && prec > 0)
	{
		write(1, "0", 1);
		i++;
	}
	return (0);
}
