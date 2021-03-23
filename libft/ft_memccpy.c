/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:04:29 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/18 17:59:21 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (b[i] != (unsigned char)c)
		{
			a[i] = b[i];
			i++;
		}
		else
		{
			a[i] = b[i];
			return (dst + i + 1);
		}
	}
	return (NULL);
}
