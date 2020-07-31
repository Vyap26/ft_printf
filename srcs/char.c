/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 21:14:11 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** char output
**
** Alignment using spaces, if width > quantity of output symbols
** Symbols output
** Alignment using spaces if there is flag "-"
*/

void	print_char(t_struct *f, va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	f->len = 1;
	if (f->width > f->len && f->minus == false)
		f->nprinted += write_space(f->width - f->len);
	f->nprinted += write(1, &c, 1);
	if (f->width > 1 && f->minus == true)
		f->nprinted += write_space(f->width - f->len);
}
