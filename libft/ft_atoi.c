/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:22:54 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/19 14:38:44 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int first;
	int znak;

	first = 0;
	znak = 1;
	while (*str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-')
		znak = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		first = first * 10 + ((int)(*str) - 48);
		str++;
	}
	return (first * znak);
}
