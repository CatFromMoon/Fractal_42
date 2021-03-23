/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:40:02 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 21:43:31 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	julia(t_f *f)
{
	f->draw.newre = f->x * 1.0 / f->draw.zoom + f->draw.movex;
	f->draw.newim = f->y * 1.0 / f->draw.zoom + f->draw.movey;
	f->i = -1;
	while (++f->i < f->draw.maxiterations)
	{
		f->draw.oldre = f->draw.newre;
		f->draw.oldim = f->draw.newim;
		f->draw.newre = f->draw.oldre * f->draw.oldre - f->draw.oldim *
										f->draw.oldim + f->draw.cre;
		f->draw.newim = 2 * f->draw.oldre * f->draw.oldim + f->draw.cim;
		if ((f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim) > 4)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}
