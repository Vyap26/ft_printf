/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:19:35 by lclay             #+#    #+#             */
/*   Updated: 2020/03/15 15:41:09 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

int			unsigned_nbr_len(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

long double	ft_power(intmax_t n, int i)
{
	long		k;
	long double	res;

	res = n;
	k = 0;
	if (i == 0)
		return (1);
	while (k < i - 1)
	{
		res = res * n;
		k++;
	}
	return (res);
}

uintmax_t	ft_round(long double n)
{
	uintmax_t	tmp;
	int			flag;
	int			i;

	flag = 0;
	i = -1;
	if (n > UINTMAX_DOUBLE)
		return (0);
	else if (n * 10 > UINTMAX_DOUBLE)
	{
		tmp = n;
		return (tmp);
	}
	else
	{
		tmp = n * 10;
		if (tmp % 10 >= 5)
			tmp = tmp / 10 + 1;
		else
			tmp /= 10;
		return (tmp);
	}
}
