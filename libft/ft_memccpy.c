/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:37:16 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:31:51 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	symb = (unsigned char)c;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	while (n > 0)
	{
		if (s1[i] == symb)
		{
			s2[i] = s1[i];
			return (dst + i + 1);
		}
		else
			s2[i] = s1[i];
		i++;
		n--;
	}
	return (0);
}
