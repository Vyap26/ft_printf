/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:40:26 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:56 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	symb;

	symb = (unsigned char)c;
	while (*s != symb)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
