/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:36:47 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/20 17:46:09 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_j(char const *s)
{
	size_t	j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j);
}

static size_t	len_i(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	start = len_i(s);
	end = len_j(s);
	str = ft_strnew(ft_strlen(s) - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
