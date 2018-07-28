/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:31:39 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 20:32:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			queue(char ****box, t_p *p)
{
	read_flags(*box, p);
	read_width(*box, p);
	read_precision(*box, p);
	read_size(*box, p);
	if (read_conv_letter(*box, p))
		return (1);
	return (0);
}

void		if_percent(t_p *p, char ***box, char **s)
{
	(*s)++;
	if (queue(&box, p))
	{
		fetch_data(&p->l, p);
		(*p->b) += choose_datatype_handler(p);
	}
	else if (***box)
	{
		write(1, *s, 1);
		(*p->b)++;
	}
}

int			ft_printf(const char *s, ...)
{
	t_p		p;
	char	**box;
	int		b;

	b = 0;
	p.b = &b;
	box = &s;
	va_start(p.l, s);
	while (**box)
	{
		if (**box == '%')
			if_percent(&p, &box, &s);
		else
		{
			write(1, s, 1);
			(*p.b)++;
		}
		if (*s)
			s++;
	}
	va_end(p.l);
	return (*p.b);
}
