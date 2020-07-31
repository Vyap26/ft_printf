/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 21:17:27 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_float(long double *n, t_struct *f, va_list ap)
{
	if (f->length == none)
		*n = (double)va_arg(ap, double);
	else if (f->length == l)
		*n = (double)va_arg(ap, double);
	else if (f->length == L)
		*n = (long double)va_arg(ap, long double);
}

void	convert_hex(uintmax_t *n, t_struct *f, va_list ap)
{
	if (f->length == none)
		*n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == hh)
		*n = (unsigned char)va_arg(ap, int);
	else if (f->length == h)
		*n = (unsigned short)va_arg(ap, int);
	else if (f->length == ll)
		*n = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (f->length == l)
		*n = (unsigned long int)va_arg(ap, uintmax_t);
}

void	convert_int(intmax_t *n, t_struct *f, va_list ap)
{
	if (f->length == none)
		*n = (int)va_arg(ap, int);
	else if (f->length == hh)
		*n = (signed char)va_arg(ap, int);
	else if (f->length == h)
		*n = (short int)va_arg(ap, int);
	else if (f->length == ll)
		*n = (long long int)va_arg(ap, long long int);
	else if (f->length == l)
		*n = (long int)va_arg(ap, long int);
}

void	convert_octal(unsigned long *n, t_struct *f, va_list ap)
{
	if (f->length == none)
		*n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == hh)
		*n = (unsigned char)va_arg(ap, unsigned int);
	else if (f->length == h)
		*n = (unsigned short int)va_arg(ap, unsigned int);
	else if (f->length == ll)
		*n = (unsigned long long)va_arg(ap, unsigned long long);
	else if (f->length == l)
		*n = (unsigned long)va_arg(ap, unsigned long);
}

void	convert_udecimalint(uintmax_t *n, t_struct *f, va_list ap)
{
	if (f->length == none)
		*n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == hh)
		*n = (unsigned char)va_arg(ap, int);
	else if (f->length == h)
		*n = (unsigned short int)va_arg(ap, int);
	else if (f->length == ll)
		*n = (unsigned long long int)va_arg(ap, long long int);
	else if (f->length == l)
		*n = (unsigned long int)va_arg(ap, long int);
}
