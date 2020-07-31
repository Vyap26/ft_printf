/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:30:25 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print_spaces(t_struct *f, int n)
{
	int	len;

	len = f->len;
	if (f->minus == false)
	{
		if (f->prec_flag == false)
		{
			len += f->sign_flag;
			if (f->width > len && f->zero == false)
				f->space_count += (f->width - len);
		}
		else
		{
			len = ft_max(len, f->precision);
			len = (f->precision == 0 && n == 0) ? 0 : len;
			len += f->sign_flag;
			if (f->width > len)
				f->space_count += (f->width - len);
		}
	}
	if (f->space_count == 0 && (f->space == true && !f->sign_flag))
		(f->space_count += 1) && (f->space_flag = true);
	f->nprinted += write_space(f->space_count);
}

void	int_print_sign(t_struct *f)
{
	if (f->negative_flag == true)
		f->nprinted += write(1, "-", 1);
	else if (f->plus == true && f->negative_flag == false)
		f->nprinted += write(1, "+", 1);
}

void	int_print_zeros(t_struct *f)
{
	int	zero_count;
	int	len;

	len = f->len;
	zero_count = 0;
	f->sign_flag = (f->negative_flag == true || f->plus == true) ? 1 : 0;
	if (f->prec_flag == true)
	{
		if (f->precision > len)
			zero_count += (f->precision - len);
	}
	else
	{
		len += f->sign_flag;
		if (f->width > len && f->zero == true && f->minus == false)
			zero_count += (f->width - len);
		if (f->space_flag == true && zero_count > 0)
			zero_count--;
	}
	f->nprinted += write_zero(zero_count);
}

void	int_print_value(t_struct *f, char *str, int n)
{
	if (!(f->prec_flag == true && f->precision == 0 && n == 0))
		f->nprinted += write(1, str, f->len);
}

void	int_print_spaces2(t_struct *f)
{
	f->nprinted_local = f->nprinted - f->nprinted_local;
	if (f->minus == true && f->width > f->nprinted_local)
		f->nprinted += write_space(f->width - f->nprinted_local);
}
