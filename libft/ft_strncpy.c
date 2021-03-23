/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:27:11 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/18 19:11:46 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*b;
	size_t	i;

	i = 0;
	b = dst;
	while (src[i] != '\0' && i < len)
	{
		b[i] = src[i];
		i++;
	}
	if (i < len)
	{
		while (i < len)
		{
			b[i] = '\0';
			i++;
		}
	}
	return (b);
}
