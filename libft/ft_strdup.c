/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:40:51 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/18 20:04:05 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str2;

	str2 = NULL;
	str2 = (char *)malloc(ft_strlen(s1) + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strcpy(str2, s1);
	return (str2);
}
