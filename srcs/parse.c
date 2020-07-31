/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/13 00:03:18 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(const char *format, t_struct *f, va_list ap, int *pos)
{
	while (format[*pos] != '\0')
	{
		if (format[*pos] != '%' && format[*pos])
			f->nprinted += write(1, &format[*pos], 1);
		else if (format[*pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[*pos + 1]))
				break ;
			else
			{
				*pos = *pos + 1;
				check_all(format, f, pos);
				if (f->type == '?')
					break ;
			}
			print_format(ap, f);
			init_struct(f);
		}
		*pos = *pos + 1;
	}
	return (f->nprinted);
}

void	check_all(const char *format, t_struct *f, int *pos)
{
	if (ft_strchr(FLAGS, format[*pos]))
		memflag(format, f, pos);
	if (ft_strchr(WIDTH, format[*pos]))
		memwidth(format, f, pos);
	if (ft_strchr(PREC, format[*pos]))
		memprec(format, f, pos);
	if (ft_strchr(MOD, format[*pos]))
		memmod(format, f, pos);
	if (ft_strchr(TYPE, format[*pos]))
		memtype(format, f, *pos);
}
