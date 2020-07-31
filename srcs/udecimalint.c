/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udecimalint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:31:02 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	udec_print_spaces(t_struct *f, int n)
{
	int	space_count;
	int	len;

	len = f->len;
	space_count = 0;
	if (f->minus == false)
	{
		if (f->prec_flag == false)
		{
			if (f->width > len && f->zero == false)
				space_count += (f->width - len);
		}
		else
		{
			len = ft_max(len, f->precision);
			len = (f->precision == 0 && n == 0) ? 0 : len;
			if (f->width > len)
				space_count += (f->width - len);
		}
	}
	f->nprinted += write_space(space_count);
}

void	udec_print_zeros(t_struct *f)
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
		if (f->width > len && f->zero == true && f->minus == false)
			zero_count += (f->width - len);
	}
	f->nprinted += write_zero(zero_count);
}

void	udec_print_value(t_struct *f, char *str, int n)
{
	if (!(f->prec_flag == true && f->precision == 0 && n == 0))
		f->nprinted += write(1, str, f->len);
}

void	udec_print_spaces2(t_struct *f)
{
	f->nprinted_local = f->nprinted - f->nprinted_local;
	if (f->minus == true && f->width > f->nprinted_local)
		f->nprinted += write_space(f->width - f->nprinted_local);
}

void	print_udecimalint(t_struct *f, va_list ap)
{
	uintmax_t	n;
	char		*str;

	f->nprinted_local = f->nprinted;
	convert_udecimalint(&n, f, ap);
	str = ft_itoa_base(n, 10);
	f->len = unsigned_nbr_len(n, 10);
	udec_print_spaces(f, n);
	udec_print_zeros(f);
	udec_print_value(f, str, n);
	udec_print_spaces2(f);
	free(str);
}
