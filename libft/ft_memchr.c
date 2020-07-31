/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:37:56 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:33 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == symb)
			return (str + i);
		i++;
		n--;
	}
	return (0);
}
