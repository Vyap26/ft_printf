/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 22:19:45 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_struct *f)
{
	f->len = 1;
	if (f->width > f->len && f->zero == false && f->minus == false)
		f->nprinted += write_space(f->width - f->len);
	if (f->width > f->len && f->zero == true && f->minus == false)
		f->nprinted += write_zero(f->width - f->len);
	f->nprinted += write(1, "%", 1);
	if (f->width > 1 && f->minus == true)
		f->nprinted += write_space(f->width - f->len);
}
