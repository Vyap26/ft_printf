/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:38:59 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:10:36 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dst;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	if (s2 < s1)
	{
		while (++i < len)
			s2[i] = s1[i];
	}
	else
	{
		while (len-- > 0)
			s2[len] = s1[len];
	}
	return (dst);
}
