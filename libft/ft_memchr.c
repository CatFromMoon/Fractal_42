/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:14:30 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/17 22:10:09 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;
	size_t		i;

	i = 0;
	a = (const char *)s;
	while (i < n)
	{
		if (*a == c)
		{
			return ((void *)a);
		}
		a++;
		i++;
	}
	return (NULL);
}
