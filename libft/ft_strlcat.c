/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:39:12 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 15:42:24 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	len_d;
	size_t	len_s;

	i = ft_strlen((char *)dst);
	j = 0;
	len_d = ft_strlen((char *)dst);
	len_s = ft_strlen((char *)src);
	if (size < len_d)
		return (len_s + size);
	while (src[j] && i < size - 1)
		*(dst + i++) = *(src + j++);
	*(dst + i) = '\0';
	return (len_d + len_s);
}
