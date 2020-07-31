/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:42:14 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:17 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	n;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		str[i] = f(n, s[i]);
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
