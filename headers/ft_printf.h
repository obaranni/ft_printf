/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ + :+         +:+    */
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
# include <locale.h>

# define POS p->pos
# define NEG !(p->pos)
# define DLEN p->data_len

typedef struct		s_properties
{
    unsigned int    *data_uint;
	unsigned int    *data_uint_copy;
	unsigned int	data_uni_char;
    char			*data;
	int 			zero;
	int 			sharp;
	int 			space;
	int 			minus;
	int 			plus;
	int 			width;
	int 			is_data_zero;
	int 			precision;
	char 			size;
	char 			conv_let;
	size_t			data_uns;
    ssize_t         data_sig;
	int 			data_len;
	int 			pos;
    int             prec_finded;
	int 			local;
}					t_p;
int 				print_any_string(t_p *p);
char        		*any_octal_to_str(t_p *p, size_t nb);
void				forme_oct(t_p *p);
int 				count_uni_string_len(unsigned int **arr);
void 				dup_arr(unsigned int **arr1, unsigned int **arr2);
void				printing_unicode(unsigned int *u);
void				masks(unsigned int *u);
char                *ft_itoa_base(size_t value, size_t base);
char				*itoa_base_sized(size_t n, int base, int size);
int					print_hex(t_p *p);
int					print_uni_char(t_p *p);
int                 print_uni_string(t_p *p);
int					print_octal(t_p *p);
int                 print_string(t_p *p);
char                *any_signed_dec_to_str(ssize_t nb);
char				*any_unsigned_dec_to_str(size_t nb);
int					print_precision(int prec);
void				print_width(int arg_len, t_p *p);
void                print_width_char(int arg_len, t_p *p);
int					printing_sig_dec(t_p *p);
int					printing_usig_dec(t_p *p);
int 				init_sign(t_p *p);
int 				find_sig_digit_len(t_p *p);
int 				find_usig_digit_len(t_p *p);
int 				choose_datatype_handler(t_p *p);
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
