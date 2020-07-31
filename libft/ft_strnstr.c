/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:42:50 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:05 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1 != '\0' && len > 0)
	{
		if (*str1 == *str2)
		{
			s1 = (char *)str1;
			s2 = (char *)str2;
			i = len;
			while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && i-- > 0)
			{
				s2++;
				s1++;
			}
			if (*s2 == '\0')
				return ((char *)str1);
		}
		str1++;
		len--;
	}
	return (NULL);
}
