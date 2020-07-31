/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 23:45:22 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_struct *f)
{
	f->nprinted_local = 0;
	f->len = 0;
	f->minus = false;
	f->plus = false;
	f->space = false;
	f->zero = false;
	f->hash = false;
	f->width = 0;
	f->precision = 0;
	f->prec_flag = false;
	f->space_flag = false;
	f->zero_flag = false;
	f->negative_flag = false;
	f->hash_flag = false;
	f->sign_flag = 0;
	f->space_count = 0;
	f->offset = 0;
	f->length = none;
	f->type = '?';
}

void	print_format(va_list ap, t_struct *f)
{
	if (f->type == 'c')
		print_char(f, ap);
	else if (f->type == 's')
		print_string(f, ap);
	else if (f->type == 'd' || f->type == 'i')
		print_int(f, ap);
	else if (f->type == 'o')
		print_octal(f, ap);
	else if (f->type == 'x' || f->type == 'X')
		print_hex(f, ap);
	else if (f->type == 'u')
		print_udecimalint(f, ap);
	else if (f->type == 'p')
		print_pointer(f, ap);
	else if (f->type == 'f')
		print_float(f, ap);
	else if (f->type == '%')
		print_percent(f);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*f;
	int			nwritten;
	int			pos;

	pos = 0;
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	f->nprinted = 0;
	init_struct(f);
	f->format = (char *)format;
	va_start(ap, format);
	if (!format[0])
	{
		error();
		return (0);
	}
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	else
		nwritten = check_format(format, f, ap, &pos);
	va_end(ap);
	free(f);
	return (nwritten);
}
