/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:47:50 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/20 18:48:04 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(char const *str, char c)
{
	int number;
	int i;

	i = 0;
	number = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			number++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (number);
}

static size_t	len(char const *str, char c)
{
	int i;
	int len_w;

	i = 0;
	len_w = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len_w++;
	}
	return (len_w);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;

	str = (char **)malloc(sizeof(*str) * (words(s, c) + 1));
	if (!s || !str)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < words(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew(len(&s[j], c) + 1)))
			str[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
