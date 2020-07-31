/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:27:45 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(t_struct *f, va_list ap)
{
	long double	n;
	long double	tmp;
	uintmax_t	n_round;
	char		*dec_part;
	char		*int_part;

	f->nprinted_local = f->nprinted;
	convert_float(&n, f, ap);
	if (f->precision == 0 && f->prec_flag == false)
		f->precision = 6;
	f->negative_flag = (n < 0) ? true : false;
	n = (n < 0) ? n * (-1) : n;
	tmp = n * ft_power(10, f->precision);
	while (tmp > UINTMAX_DOUBLE)
		(tmp = tmp / 10) && f->offset++;
	f->precision -= f->offset;
	n_round = ft_round(tmp);
	dec_part = float_get_dec_part(f, n_round);
	int_part = float_get_int_part(f, n_round);
	f->len = float_get_output_len(f, int_part);
	float_print_spaces(f);
	float_print_sign(f);
	float_print_zeros(f);
	float_print_value(f, int_part, dec_part);
	float_print_spaces2(f);
}
