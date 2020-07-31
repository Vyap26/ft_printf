/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:40:48 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_get_dec_part(t_struct *f, long long n)
{
	char	*dec_p;
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_itoa_base(n, 10);
	i = 0;
	len = ft_strlen(tmp);
	f->zero_flag = (len <= f->precision) ? true : false;
	if (f->zero_flag == true)
	{
		if (!(dec_p = (char *)malloc(sizeof(char) * (len + 1))))
			error();
		dec_p = ft_strcpy(dec_p, tmp);
		return (dec_p);
	}
	if (!(dec_p = (char *)malloc(sizeof(char) * (f->precision + 1))))
		error();
	while (i < f->precision)
	{
		dec_p[i] = tmp[len - f->precision + i];
		i++;
	}
	dec_p[i] = '\0';
	return (dec_p);
}

void	float_print_dec_part(t_struct *f, char *dec_p)
{
	char	*dec_part;
	int		dec_len;

	dec_len = ft_strlen(dec_p);
	dec_part = dec_p;
	if (dec_len < f->precision)
		f->nprinted += write_zero(f->precision - dec_len);
	f->nprinted += write(1, dec_part, dec_len);
	free(dec_part);
}

void	float_print_value(t_struct *f, char *int_part, char *dec_part)
{
	float_print_int_part(f, int_part);
	if (f->precision != 0 || f->hash == true)
		f->nprinted += write(1, ".", 1);
	float_print_dec_part(f, dec_part);
	f->nprinted += write_zero(f->offset);
}

void	float_print_spaces2(t_struct *f)
{
	f->nprinted_local = f->nprinted - f->nprinted_local;
	if (f->minus == true && f->width > f->nprinted_local)
		f->nprinted += write_space(f->width - f->nprinted_local);
}

int		float_get_output_len(t_struct *f, char *int_p)
{
	int	len;
	int	sign_flag;

	len = 0;
	len += ft_strlen(int_p);
	if (f->precision > 0)
	{
		len += f->precision;
		len += 1;
	}
	sign_flag = (f->negative_flag == true || f->plus == true) ? 1 : 0;
	len += sign_flag;
	return (len);
}
