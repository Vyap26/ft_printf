/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:41:06 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:27 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
