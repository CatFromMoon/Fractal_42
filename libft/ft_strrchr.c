/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 20:18:55 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 14:43:17 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (*(a + i) == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
