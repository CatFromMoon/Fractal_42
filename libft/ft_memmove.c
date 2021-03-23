/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:02:11 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/18 20:21:37 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;

	i = -1;
	a = (char *)src;
	b = (char *)dst;
	if (a < b)
		while ((int)(--len) >= 0)
			*(b + len) = *(a + len);
	else
		while (++i < len)
			*(b + i) = *(a + i);
	return (dst);
}
