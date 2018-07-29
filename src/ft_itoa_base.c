/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:58:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:59:29 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	f_len(size_t nbr)
{
	int		size;

	size = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static char	set_char(size_t i)
{
	char	c;

	c = 'Z';
	if (i <= 9)
		c = i + '0';
	else if (i == 10)
		c = 'A';
	else if (i == 11)
		c = 'B';
	else if (i == 12)
		c = 'C';
	else if (i == 13)
		c = 'D';
	else if (i == 14)
		c = 'E';
	else if (i == 15)
		c = 'F';
	return (c);
}

static void	f(size_t value, size_t base, char *s, int *i)
{
	if (value >= base)
		f(value / base, base, s, i);
	s[(*i)++] = set_char(value % base);
}

char		*ft_itoa_base(size_t value, size_t base)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = f_len(value) + 1;
	if (base < 2 || base > 16 || !(s = (char*)malloc(sizeof(char) * len)))
		return (0);
	f(value, base, s, &i);
	s[i] = '\0';
	return (s);
}
