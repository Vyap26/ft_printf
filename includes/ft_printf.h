/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:31:52 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:41:50 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include "../libft/libft.h"

# define ALLSYMBOLS 	"cspdiouxXf#-+ .*0123456789hLljz%"
# define FLAGS "#-+ 0"
# define WIDTH "123456789"
# define PREC "."
# define MOD "lhLjz"
# define TYPE "csdioxXupf%"
# define NUMBERS "1234567890"

# define UINTMAX_DOUBLE 18446744073709551615.0

typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	none,
	hh,
	h,
	L,
	l,
	ll
}	t_length;

typedef enum
{
	c,
	s,
	d,
	i,
	o,
	x,
	X,
	u,
	p,
	f
}	t_format;

/*
** format - all that is after %
** type
** nprinted
** nprinted_local
** len
** minus
** plus
** space
** zero
** hash
** prec_flag - in case precision = 0
** space_flag - in case the space (probel) flag is activated
** zero_flag - in case the value is zero (needed for float)
** negative_flag - in case the value is zero (needed for float)
** hash_flag
** sign_flag
** space_count
** width - 0 - 9
** precision - .
** length - ll l hh h L
*/

typedef struct			s_struct
{
	char				*format;
	char				type;

	int					nprinted;
	int					nprinted_local;
	int					len;

	t_bool				minus;
	t_bool				plus;
	t_bool				space;
	t_bool				zero;
	t_bool				hash;

	t_bool				prec_flag;
	t_bool				space_flag;
	t_bool				zero_flag;
	t_bool				negative_flag;
	t_bool				hash_flag;
	int					sign_flag;
	int					space_count;
	int					offset;

	int					width;
	int					precision;
	t_length			length;

}						t_struct;

void					init_struct(t_struct *f);

void					print_char(t_struct *f, va_list ap);
void					print_percent(t_struct *f);
void					print_string(t_struct *f, va_list ap);

void					int_print_spaces(t_struct *f, int n);
void					int_print_sign(t_struct *f);
void					int_print_zeros(t_struct *f);
void					int_print_value(t_struct *f, char *str, int n);
void					int_print_spaces2(t_struct *f);
void					print_int(t_struct *f, va_list ap);

void					float_print_spaces(t_struct *f);
void					float_print_sign(t_struct *f);
void					float_print_zeros(t_struct *f);
char					*float_get_int_part(t_struct *f, long long n);
void					float_print_int_part(t_struct *f, char *int_p);
char					*float_get_dec_part(t_struct *f, long long n);
void					float_print_dec_part(t_struct *f, char *dec_p);
void					float_print_value(t_struct *f, char *int_part, \
											char *dec_part);
void					float_print_spaces2(t_struct *f);
int						float_get_output_len(t_struct *f, char *int_p);
void					print_float(t_struct *f, va_list ap);

void					convert_float(long double *n, t_struct *f, va_list ap);
void					convert_hex(uintmax_t *n, t_struct *f, va_list ap);
void					convert_int(intmax_t *n, t_struct *f, va_list ap);
void					convert_octal(unsigned long *n, t_struct *f, \
										va_list ap);
void					convert_udecimalint(uintmax_t *n, t_struct *f, \
										va_list ap);

void					hex_print_spaces(t_struct *f, int n);
void					hex_print_hash(t_struct *f, int n);
void					hex_print_zeros(t_struct *f);
void					hex_print_value(t_struct *f, char *str, int n);
void					hex_print_spaces2(t_struct *f);
void					print_hex(t_struct *f, va_list ap);

void					oct_print_spaces(t_struct *f, int n);
void					oct_print_zeros(t_struct *f);
void					oct_print_hash(t_struct *f, int n);
void					oct_print_value(t_struct *f, char *str, int n);
void					oct_print_spaces2(t_struct *f);
void					print_octal(t_struct *f, va_list ap);

void					print_pointer(t_struct *f, va_list ap);
void					print_udecimalint(t_struct *f, va_list ap);
void					print_format(va_list ap, t_struct *f);

char					*ft_itoa_base(uintmax_t value, uintmax_t base);
int						unsigned_nbr_len(uintmax_t n, int base);
char					*ft_toupper_str(char *str);
long double				ft_power(intmax_t n, int i);
uintmax_t				ft_round(long double n);
int						write_zero(int n);
int						write_space(int n);
int						write_0x(t_bool upper);
int						ft_max(int a, int b);
void					error();

int						check_format(const char *format, t_struct *f, \
									va_list ap, int *pos);
int						parse_format(const char *format, t_struct *f, \
									va_list ap, int *pos);
void					check_all(const char *format, t_struct *f, int *pos);

void					memflag(const char *format, t_struct *f, int *pos);
void					memwidth(const char *format, t_struct *f, int *pos);
void					memprec(const char *format, t_struct *f, int *pos);
void					memmod(const char *format, t_struct *f, int *pos);
void					memtype(const char *format, t_struct *f, int pos);

int						ft_printf(const char *format, ...);

#endif
