/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:09:38 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 20:26:21 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	ship(t_f *f)
{
	f->draw.cre = f->x * 1.0 / f->draw.zoom + f->draw.movex - 0.5;
	f->draw.cim = f->y * 1.0 / f->draw.zoom + f->draw.movey - 0.5;
	f->draw.newre = 0;
	f->draw.newim = 0;
	f->i = -1;
	while (++f->i < f->draw.maxiterations)
	{
		f->draw.oldre = f->draw.newre;
		f->draw.oldim = f->draw.newim;
		f->draw.newre = f->draw.oldre * f->draw.oldre -
					f->draw.oldim * f->draw.oldim + f->draw.cre;
		f->draw.newim = 2 * fabs(f->draw.oldre * f->draw.oldim) + f->draw.cim;
		if (f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim > 4)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}

void	dich(t_f *f)
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
		f->draw.newre = f->draw.oldre * f->draw.oldre * f->draw.oldre *
			f->draw.oldre + f->draw.oldim * f->draw.oldim * f->draw.oldim *
		f->draw.oldim - 2 * f->draw.oldim * f->draw.oldim * f->draw.oldre *
												f->draw.oldre + f->draw.cre;
		f->draw.newim = 4 * f->draw.oldre * f->draw.oldim * (f->draw.oldim *
				f->draw.oldim + f->draw.oldre * f->draw.oldre) + f->draw.cim;
		if ((f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim) > 8)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}

void	ship2(t_f *f)
{
	f->draw.cre = f->x * 1.0 / f->draw.zoom + f->draw.movex;
	f->draw.cim = f->y * 1.0 / f->draw.zoom + f->draw.movey;
	f->draw.newre = 0;
	f->draw.newim = 0;
	f->i = -1;
	while (++f->i < f->draw.maxiterations)
	{
		f->draw.oldre = f->draw.newre;
		f->draw.oldim = f->draw.newim;
		f->draw.newre = f->draw.oldre * f->draw.oldre - f->draw.oldim *
											f->draw.oldim + f->draw.cre;
		f->draw.newim = -2 * f->draw.oldre * f->draw.oldim + f->draw.cim;
		if (f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim > 4)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}

void	mandelbrot2(t_f *f)
{
	f->draw.cre = f->x * 1.0 / f->draw.zoom + f->draw.movex;
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
		f->draw.newre = f->draw.oldre * f->draw.oldre * f->draw.oldre - 3 *
					f->draw.oldre * f->draw.oldim * f->draw.oldim + f->draw.cre;
		f->draw.newim = 3 * f->draw.oldre * f->draw.oldre * f->draw.oldim -
					f->draw.oldim * f->draw.oldim * f->draw.oldim + f->draw.cim;
		if ((f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim) > 4)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}

void	mandelbrotsin(t_f *f)
{
	f->draw.cre = f->x * 1.0 / f->draw.zoom + f->draw.movex;
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
		f->draw.newre = sin(f->draw.oldre * f->draw.oldre -
							f->draw.oldim * f->draw.oldim + f->draw.cre);
		f->draw.newim = 2 * f->draw.oldre * f->draw.oldim + f->draw.cim;
		if ((f->draw.newre * f->draw.newre + f->draw.newim * f->draw.newim) > 4)
			break ;
	}
	(f->i == f->draw.maxiterations) ? put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color) : put_pixel_in_img(f, f->x, f->y, f->i *
			f->i * f->i * f->color);
}
