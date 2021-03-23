/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:13:55 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 15:32:54 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = -1;
	k = ft_strlen(needle);
	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (!(ft_strlen((char*)haystack) < ft_strlen((char*)needle)))
		while (haystack[++i] && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				if (k == j + 1)
					return ((char *)haystack + i);
				j++;
			}
		}
	return (NULL);
}
