/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:07:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 17:08:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_properties
{
	int 			zero;
	int 			sharp;
	int 			space;
	int 			minus;
	int 			plus;
	int 			width;
	int 			precision;
	char 			size;
	char 			conv_let;
	void			*data;
}					t_p;
void				print_width(int arg_len, t_p *p);
void				ft_putnbr_unsig(int n);
int					sign_int_dec(t_p *p);
int					read_flags(char ***s, t_p *p);
int					read_width(char ***s, t_p *p);
int					read_precision(char ***s, t_p *p);
int			 		read_size(char ***s, t_p *p);
int					read_conv_letter(char ***s, t_p *p);
int					flags_priority(t_p *p, int digit);
int					fetch_data(va_list *l, t_p *p);
int					digit_len(int a);
int					calc_arg_len(int d, t_p *p);
int					ft_printf(char *s, ...);

#endif
