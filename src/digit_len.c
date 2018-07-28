/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:53:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 18:54:58 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int					init_sign(t_p *p)
{
	int				flag;

	flag = 0;
	if (p->size == 'z')
		(intmax_t)p->data_sig < 0 ? flag = 1 : 0;
	else if (p->size == 'j')
		(intmax_t)p->data_sig < 0 ? flag = 1 : 0;
	else if (p->size == 'L')
		(long long int)p->data_sig < 0 ? flag = 1 : 0;
	else if (p->size == 'l')
		(long)p->data_sig < 0 ? flag = 1 : 0;
	else if (p->size == 'h')
		(short)p->data_sig < 0 ? flag = 1 : 0;
	else if (p->size == 'H')
		(char)p->data_sig < 0 ? flag = 1 : 0;
	else
		(int)p->data_sig < 0 ? flag = 1 : 0;
	p->pos = 1;
	if (flag)
		p->pos = 0;
	return (0);
}

int					digit_len_uns(size_t digit)
{
	int				i;

	i = 0;
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}

int					digit_len_sig(ssize_t digit)
{
	int				i;

	i = 0;
	if (digit == 0)
		return (1);
	while (digit > 0 || digit < 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}

int					find_sig_digit_len(t_p *p)
{
	if (p->size == 'z')
		p->data_len = digit_len_sig(p->data_sig);
	else if (p->size == 'j')
		p->data_len = digit_len_sig((intmax_t)p->data_sig);
	else if (p->size == 'L')
		p->data_len = digit_len_sig(p->data_sig);
	else if (p->size == 'l')
		p->data_len = digit_len_sig(((long)p->data_sig));
	else if (p->size == 'h')
		p->data_len = digit_len_sig(((short)p->data_sig));
	else if (p->size == 'H')
		p->data_len = digit_len_sig(((char)p->data_sig));
	else
		p->data_len = digit_len_sig(((int)p->data_sig));
	return (0);
}

int					find_usig_digit_len(t_p *p)
{
	if (p->size == 'z')
		p->data_len = digit_len_uns((size_t)p->data_uns);
	else if (p->size == 'j')
		p->data_len = digit_len_uns((intmax_t)p->data_uns);
	else if (p->size == 'L')
		p->data_len = digit_len_uns((unsigned long long)p->data_uns);
	else if (p->size == 'l')
		p->data_len = digit_len_uns(((unsigned long long)p->data_uns));
	else if (p->size == 'h')
		p->data_len = digit_len_uns(((unsigned short)p->data_uns));
	else if (p->size == 'H')
		p->data_len = digit_len_uns(((unsigned char)p->data_uns));
	else
		p->data_len = digit_len_uns(((unsigned int)p->data_uns));
	return (0);
}
