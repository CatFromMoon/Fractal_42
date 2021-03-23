/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:44 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 21:49:36 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	mandelbrot(t_f *f)
{
	f->draw.cre = f->x * 1.0 / f->draw.zoom + f->draw.movex - 0.5;
	f->draw.cim = f->y * 1.0 / f->draw.zoom + f->draw.movey;
	f->draw.newim = 0;
	f->draw.newre = 0;
	f->draw.oldre = 0;
	f->draw.oldim = 0;
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
