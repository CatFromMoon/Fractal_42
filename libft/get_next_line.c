/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:49:11 by mchudik           #+#    #+#             */
/*   Updated: 2018/12/08 14:49:13 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const int fd, char *mass, char *rezmass[fd])
{
	int			i;
	char		*sup;

	while (ft_strchr(mass, 10) == NULL \
			&& (i = read(fd, mass, BUFF_SIZE)) > 0)
	{
		mass[i] = '\0';
		sup = rezmass[fd];
		rezmass[fd] = ft_strjoin(sup, mass);
		ft_strdel(&sup);
	}
	ft_strdel(&mass);
	if (i == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*mass;
	static char	*rezmass[BUFF_SIZE + 1];
	char		*pl;
	char		*leak;

	if (fd < 0 || !line || BUFF_SIZE < 1
		|| read(fd, rezmass[BUFF_SIZE], 0) != 0)
		return (-1);
	if (rezmass[fd] == NULL)
		rezmass[fd] = ft_strnew(1);
	mass = ft_strnew(BUFF_SIZE);
	if (ft_check(fd, mass, rezmass) == -1)
		return (-1);
	if ((pl = ft_strchr(rezmass[fd], '\n')) != NULL)
	{
		*line = ft_strsub(rezmass[fd], 0, pl - rezmass[fd]);
		leak = rezmass[fd];
		rezmass[fd] = ft_strdup(pl + 1);
		ft_strdel(&leak);
		return (1);
	}
	*line = ft_strdup(rezmass[fd]);
	ft_strdel(&rezmass[fd]);
	ft_strdel(&pl);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
