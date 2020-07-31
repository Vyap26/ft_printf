/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 22:01:08 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_print_spaces(t_struct *f)
{
	int	sign_flag;
	int	space_count;

	space_count = 0;
	sign_flag = (f->negative_flag == true || f->plus == true) ? 1 : 0;
	if (f->minus == false)
	{
		if (f->width > f->len && f->zero == false)
			space_count += (f->width - f->len);
	}
	if (space_count == 0 && (f->space == true && !sign_flag))
	{
		space_count += 1;
		f->space_flag = true;
	}
	f->nprinted += write_space(space_count);
}

void	float_print_sign(t_struct *f)
{
	if (f->negative_flag == true)
		f->nprinted += write(1, "-", 1);
	else if (f->plus == true && f->negative_flag == false)
		f->nprinted += write(1, "+", 1);
}

void	float_print_zeros(t_struct *f)
{
	int	zero_count;

	zero_count = 0;
	if (f->width > f->len && f->zero == true && f->minus == false)
		zero_count += (f->width - f->len);
	if (f->space_flag == true && zero_count > 0)
		zero_count--;
	f->nprinted += write_zero(zero_count);
}

char	*float_get_int_part(t_struct *f, long long n)
{
	char	*int_p;
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = ft_itoa_base(n, 10);
	if (f->zero_flag == true)
	{
		if (!(int_p = (char *)malloc(sizeof(char) * 2)))
			error();
		int_p[0] = '0';
		int_p[1] = '\0';
		return (int_p);
	}
	len = ft_strlen(tmp);
	if (!(int_p = (char *)malloc(sizeof(char) * (len - f->precision + 1))))
		error();
	while (i < len - f->precision)
	{
		int_p[i] = tmp[i];
		i++;
	}
	int_p[i] = '\0';
	return (int_p);
}

void	float_print_int_part(t_struct *f, char *int_p)
{
	int	int_len;

	int_len = ft_strlen(int_p);
	f->nprinted += write(1, int_p, int_len);
	free(int_p);
}
