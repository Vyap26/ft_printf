/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 21:07:12 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_print_symbols(t_struct *f)
{
	if (f->width > f->len && f->minus == false)
	{
		if (f->zero == false)
			f->nprinted += write_space(f->width - f->len);
		else
			f->nprinted += write_zero(f->width - f->len);
	}
}

void	str_print_value(t_struct *f, char *str)
{
	int	i;

	i = 0;
	if (f->precision != 0 && f->precision < f->len)
	{
		while (i < f->precision)
		{
			f->nprinted += write(1, &str[i], 1);
			i++;
		}
	}
	else if (!(f->precision == 0 && f->prec_flag == true))
		f->nprinted += write(1, str, f->len);
}

void	print_string(t_struct *f, va_list ap)
{
	char	*str;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	f->len = ft_strlen(str);
	if (f->prec_flag == true)
		f->len = (f->len > f->precision) ? f->precision : f->len;
	str_print_symbols(f);
	str_print_value(f, str);
	if (f->minus == true && f->width > f->len)
		f->nprinted += write_space(f->width - f->len);
}
