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

# define POS p->pos
# define NEG !(p->pos)
# define DLEN p->data_len

typedef struct		s_properties
{
    char			*data;
	int 			zero;
	int 			sharp;
	int 			space;
	int 			minus;
	int 			plus;
	int 			width;
	int 			precision;
	char 			size;
	char 			conv_let;
	size_t			data_uns;
    ssize_t         data_sig;
	int 			data_len;
	int 			pos;
}					t_p;
char                *strings(t_p *p);
char                *any_signed_dec_to_str(ssize_t nb);
char				*any_unsigned_dec_to_str(size_t nb);
int					print_precision(int prec);
void				print_width(int arg_len, t_p *p);
char 				*long_long_toa(ssize_t n);
int					print_sig_dec(t_p *p);
int					print_usig_dec(t_p *p);
int 				init_sign(t_p *p);
int 				find_sig_digit_len(t_p *p);
int 				find_usig_digit_len(t_p *p);
int 				choose_datatype_handler(t_p *p);
int 				type_cast(t_p *p);
void				print_width(int arg_len, t_p *p);
int					int_to_sign_dec(t_p *p);
int					int_to_unsign_dec(t_p *p);
int					read_flags(char ***s, t_p *p);
int					read_width(char ***s, t_p *p);
int					read_precision(char ***s, t_p *p);
int			 		read_size(char ***s, t_p *p);
int		            letter(t_p *p);
int					read_conv_letter(char ***s, t_p *p);
int					flags_priority(t_p *p);
int					fetch_data(va_list *l, t_p *p);
int 				digit_len_sig(ssize_t digit);
int                 digit_len_uns(size_t digit);
int					calc_arg_len(t_p *p);
int					ft_printf(char *s, ...);

#endif
