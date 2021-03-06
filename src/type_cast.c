/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:39:04 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:39:06 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			type_cast(t_p *p)
{
	if (p->size == 'z')
		printf("I will cast it to size_t!\n");
	else if (p->size == 'j')
		printf("I will cast it to intmax_t!\n");
	else if (p->size == 'L')
		printf("I will cast it to long long!\n");
	else if (p->size == 'l')
		printf("I will cast it to long!\n");
	else if (p->size == 'h')
		printf("I will cast it to short!\n");
	else if (p->size == 'H')
		printf("I will cast it to char!\n");
	return (0);
}
