/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:35:05 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:29:59 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_sign_n_cut(const char **str)
{
	int sign;

	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		*str += 1;
	}
	while (**str == '0')
		*str += 1;
	return (sign);
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	int					i;

	res = 0;
	i = 0;
	sign = get_sign_n_cut(&str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res > 9223372036854775807 || i > 19) && sign == 1)
		return (-1);
	else if ((res > 9223372036854775807 || i > 19) && sign == -1)
		return (0);
	return ((int)(res * sign));
}
