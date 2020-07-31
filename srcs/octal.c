/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:32:55 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_octal(t_struct *f, va_list ap)
{
	unsigned long	n;
	char			*str;

	f->nprinted_local = f->nprinted;
	convert_octal(&n, f, ap);
	str = ft_itoa_base(n, 8);
	f->len = unsigned_nbr_len(n, 8);
	oct_print_spaces(f, n);
	oct_print_hash(f, n);
	oct_print_zeros(f);
	oct_print_value(f, str, n);
	oct_print_spaces2(f);
	free(str);
}
