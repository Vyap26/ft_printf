/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/12 22:20:36 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_space(int n)
{
	int i;

	i = n;
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
	return (i);
}

int		write_zero(int n)
{
	int i;

	i = n;
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
	return (i);
}

int		write_0x(t_bool upper)
{
	int	i;

	i = 2;
	if (upper == true)
		write(1, "0X", i);
	else if (upper == false)
		write(1, "0x", i);
	return (i);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	error(void)
{
	write(1, "", 0);
}
