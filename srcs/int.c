/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:30:26 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_struct *f, va_list ap)
{
	intmax_t	n;
	char		*str;

	f->nprinted_local = f->nprinted;
	convert_int(&n, f, ap);
	f->negative_flag = (n < 0) ? true : false;
	n = (n < 0) ? n * (-1) : n;
	f->sign_flag = (f->negative_flag == true || f->plus == true) ? 1 : 0;
	if (n == LLONG_MIN)
	{
		f->nprinted += write(1, "-9223372036854775808", 20);
		return ;
	}
	str = ft_itoa_base(n, 10);
	f->len = unsigned_nbr_len(n, 10);
	int_print_spaces(f, n);
	int_print_sign(f);
	int_print_zeros(f);
	int_print_value(f, str, n);
	int_print_spaces2(f);
	free(str);
}
