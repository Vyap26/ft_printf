/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 21:07:32 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	memflag(const char *format, t_struct *f, int *pos)
{
	while (format[*pos] && (ft_strchr(FLAGS, format[*pos])))
	{
		if (format[*pos] == '#')
			f->hash = true;
		if (format[*pos] == '+')
			f->plus = true;
		if (format[*pos] == '-')
			f->minus = true;
		if (format[*pos] == '0')
			f->zero = true;
		if (format[*pos] == ' ')
			f->space = true;
		*pos = *pos + 1;
	}
}

void	memwidth(const char *format, t_struct *f, int *pos)
{
	int n;

	n = 0;
	while (format[*pos] && (ft_strchr(NUMBERS, format[*pos])))
	{
		n = format[*pos] - 48;
		f->width = f->width * 10 + n;
		*pos = *pos + 1;
	}
}

void	memprec(const char *format, t_struct *f, int *pos)
{
	int n;

	n = 0;
	f->prec_flag = true;
	*pos = *pos + 1;
	while (format[*pos] && (ft_strchr(NUMBERS, format[*pos])))
	{
		n = format[*pos] - 48;
		f->precision = f->precision * 10 + n;
		*pos = *pos + 1;
	}
}

void	memmod(const char *format, t_struct *f, int *pos)
{
	int	n;

	n = 0;
	if (ft_strchr(MOD, format[*pos]))
	{
		if (format[*pos] == 'h')
		{
			if (format[*pos + 1] == 'h')
				f->length = hh;
			else if (format[*pos - 1] != 'h')
				f->length = h;
		}
		if (format[*pos] == 'l')
		{
			if (format[*pos + 1] == 'l')
				f->length = ll;
			else if (format[*pos - 1] != 'l')
				f->length = l;
		}
		if (format[*pos] == 'L')
			f->length = L;
	}
	while (ft_strchr(MOD, format[*pos]))
		*pos = *pos + 1;
}

void	memtype(const char *format, t_struct *f, int pos)
{
	if (format[pos] == 'c')
		f->type = 'c';
	else if (format[pos] == 's')
		f->type = 's';
	else if (format[pos] == 'd')
		f->type = 'd';
	else if (format[pos] == 'i')
		f->type = 'i';
	else if (format[pos] == 'o')
		f->type = 'o';
	else if (format[pos] == 'x')
		f->type = 'x';
	else if (format[pos] == 'X')
		f->type = 'X';
	else if (format[pos] == 'u')
		f->type = 'u';
	else if (format[pos] == 'p')
		f->type = 'p';
	else if (format[pos] == 'f')
		f->type = 'f';
	else if (format[pos] == '%')
		f->type = '%';
}
