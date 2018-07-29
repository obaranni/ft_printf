/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uni_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:32:15 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/28 21:34:03 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void				uni_char_shame(t_p *p,
		int *arg_len, int *res, unsigned int **c)
{
	if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
	{
//		*c = (unsigned int *)malloc(sizeof(unsigned int) * 2);
//		*c[0] = p->data_uni_char;
//		*c[1] = 0;
		if (p->width > 0)
		{
			p->width = p->width - count_uni_string_len(c);
			if (p->width < 0)
				p->width = 0;
		}
		(*arg_len) = p->width;
		(*res) = (*arg_len) + count_uni_string_len(c);
//		masks(*c);
	}
	else
	{
		if (p->width > 0)
			p->width--;
		(*arg_len) = p->width;
		(*res) = (*arg_len) + 1;
		*c = &p->data_uni_char;
	}
}

void				uni_char_shame2(t_p *p,
		int *arg_len, unsigned int **c)
{
	if (p->minus)
	{
		print_precision(p->precision);
		if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
			printing_unicode(*c);
		else
			write(1, *c, 1);
		print_width_char((*arg_len), p);
	}
	else
	{
		print_width_char((*arg_len), p);
		print_precision(p->precision);
		if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
			printing_unicode(*c);
		else
			write(1, *c, 1);
	}
}

int					print_uni_char(t_p *p)
{
	unsigned int	*c;
	int				arg_len;
	int				res;

	flags_priority(p);
	p->plus = 0;
	if (p->data_uni_char == 0)
	{
		if (p->width > 0)
			arg_len = p->width - 1;
		else
			arg_len = 0;
		print_width_char(arg_len, p);
		write(1, "", 1);
		return (arg_len + 1);
	}
	uni_char_shame(p, &arg_len, &res, &c);
	p->precision = 0;
//	uni_char_shame2(p, &arg_len, &c);
//	if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
//		free(c);
	return (res);
}

//int		print_uni_char(t_p *p)
//{
//    unsigned int *c;
//    int arg_len;
//    int res;
//
//    flags_priority(p);
//    p->plus = 0;
//
//    if (p->data_uni_char == 0)
//    {
//        if (p->width > 0)
//            arg_len = p->width - 1;
//        else
//            arg_len = 0;
//        print_width_char(arg_len, p);
//        write(1, "", 1);
//        return (arg_len + 1);
//    }
//
//
//
//    if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
//    {
//        c = (unsigned int *)malloc(sizeof(unsigned int) * 2);
//        c[0] = p->data_uni_char;
//        c[1] = 0;
//        if (p->width > 0)
//        {
//            p->width = p->width - count_uni_string_len(&c);
//            if (p->width < 0)
//                p->width = 0;
//        }
//        arg_len = p->width;
//        res = arg_len + count_uni_string_len(&c);
//        masks(c);
//    }
//    else
//    {
//        if (p->width > 0)
//            p->width--;
//        arg_len = p->width;
//        res = arg_len + 1;
//        c = &p->data_uni_char;
//    }
//    p->precision = 0;
//
//
//
//    if (p->minus)
//    {
//        print_precision(p->precision);
//        if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
//            printing_unicode(c);
//        else
//            write(1, c, 1);
//        print_width_char(arg_len, p);
//    }
//    else
//    {
//        print_width_char(arg_len, p);
//        print_precision(p->precision);
//        if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
//            printing_unicode(c);
//        else
//            write(1, c, 1);
//    }
//	if ((p->conv_let == 'C' || (p->conv_let == 'c' && p->size == 'l')))
//		free(c);
//    return (res);
//}