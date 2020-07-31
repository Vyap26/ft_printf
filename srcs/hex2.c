/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:30:44 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_print_spaces(t_struct *f, int n)
{
	int	space_count;
	int	len;

	len = f->len;
	space_count = 0;
	len = (f->hash == true && n != 0) ? len + 2 : len;
	if (f->minus == false)
	{
		if (f->prec_flag == false)
		{
			if (f->width > len && f->zero == false)
				space_count += (f->width - len);
		}
		else
		{
			len = ft_max(f->len, f->precision);
			len = (f->hash == true && n != 0) ? len + 2 : len;
			len = (f->precision == 0 && n == 0) ? 0 : len;
			if (f->width > len)
				space_count += (f->width - len);
		}
	}
	f->nprinted += write_space(space_count);
}

void	hex_print_hash(t_struct *f, int n)
{
	if (f->hash == true && n != 0)
		f->hash_flag = true;
	if (f->hash_flag == true)
	{
		if (f->type == 'x')
			f->nprinted += write_0x(false);
		else if (f->type == 'X')
			f->nprinted += write_0x(true);
	}
}

void	hex_print_zeros(t_struct *f)
{
	int	zero_count;
	int	len;

	len = f->len;
	zero_count = 0;
	if (f->prec_flag == true)
	{
		if (f->precision > len)
			zero_count += (f->precision - len);
	}
	else
	{
		len = (f->hash_flag == true) ? len + 2 : len;
		if (f->width > len && f->zero == true && f->minus == false)
			zero_count += (f->width - len);
	}
	f->nprinted += write_zero(zero_count);
}

void	hex_print_value(t_struct *f, char *str, int n)
{
	if (!(f->prec_flag == true && f->precision == 0 && n == 0))
		f->nprinted += write(1, str, f->len);
}

void	hex_print_spaces2(t_struct *f)
{
	f->nprinted_local = f->nprinted - f->nprinted_local;
	if (f->minus == true && f->width > f->nprinted_local)
		f->nprinted += write_space(f->width - f->nprinted_local);
}
