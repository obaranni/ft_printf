/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_signed_dec_to_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:35:32 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/29 19:42:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int		f_len(ssize_t nbr)
{
	int			size;

	size = 1;
	if (nbr == -9223372036854775808LLU)
		return (19);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size++);
}

static char		set_char(ssize_t i)
{
	char		c;

	c = 'Z';
	if (i < 0)
		i = -i;
	if (i >= 0 && i <= 9)
		c = (char)(i + '0');
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

static void		fill(ssize_t value, ssize_t base, char *s, int *i)
{
	if (value <= -base || value >= base)
		fill(value / base, base, s, i);
	s[(*i)++] = set_char(value % base);
}

char			*ft_itoa_base_nominus(ssize_t value, ssize_t base)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	len = f_len(value);
	if (base < 2 || base > 16 || !(s = (char*)malloc(sizeof(char) * len)))
		return (0);
	fill(value, base, s, &i);
	s[len] = '\0';
	return (s);
}

char			*any_signed_dec_to_str(ssize_t nb)
{
	return (ft_itoa_base_nominus(nb, 10));
}
