/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:16:59 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 17:23:44 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*a;

	if (!s)
		return (NULL);
	a = ft_strnew(ft_strlen(s));
	if (!a)
		return (NULL);
	i = 0;
	while (s[i])
	{
		a[i] = f(s[i]);
		i++;
	}
	return (a);
}
