/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:30:19 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 17:54:23 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	str_i;
	int				k;

	k = len(n);
	str_i = n;
	if (n < 0)
	{
		k++;
		str_i = -n;
	}
	if (!(str = ft_strnew(k)))
		return (NULL);
	str[--k] = str_i % 10 + '0';
	while (str_i /= 10)
	{
		str[--k] = str_i % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
