/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:30:45 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_struct *f, va_list ap)
{
	uintmax_t	n;
	char		*str;

	f->nprinted_local = f->nprinted;
	convert_hex(&n, f, ap);
	str = ft_itoa_base(n, 16);
	if (f->type == 'X')
		str = ft_toupper_str(str);
	f->len = unsigned_nbr_len(n, 16);
	hex_print_spaces(f, n);
	hex_print_hash(f, n);
	hex_print_zeros(f);
	hex_print_value(f, str, n);
	hex_print_spaces2(f);
	free(str);
}
