/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 22:20:14 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_struct *f, va_list ap)
{
	unsigned long long	ptr;
	char				*str;

	ptr = (unsigned long long)va_arg(ap, void *);
	str = ft_itoa_base(ptr, 16);
	f->len = unsigned_nbr_len(ptr, 16);
	if (f->width > f->len + 2 && f->minus == false)
		f->nprinted += write_space(f->width - (f->len + 2));
	f->nprinted += write(1, "0x", 2);
	if (f->len < f->precision)
		f->nprinted += write_zero(f->precision - f->len);
	if (!(f->prec_flag == true && f->precision == 0))
		f->nprinted += write(1, str, f->len);
	if (f->width > f->len + 2 && f->minus == true)
		f->nprinted += write_space(f->width - (f->len + 2));
	free(str);
}
