/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:26:46 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 17:27:48 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
