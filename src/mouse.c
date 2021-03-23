/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:02:40 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 20:06:42 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

int	mouse_close(int key, t_f *f)
{
	key = 1;
	exit(1);
	return (0);
}

int	mouse_release(int key, int x, int y, t_f *f)
{
	if (key == 4)
	{
		f->draw.movex = (x / f->draw.zoom + f->draw.movex) -
						(x / (f->draw.zoom * 0.9));
		f->draw.movey = (y / f->draw.zoom + f->draw.movey) -
						(y / (f->draw.zoom * 0.9));
		f->draw.zoom *= 0.9;
	}
	if (key == 5)
	{
		f->draw.movex = (x / f->draw.zoom + f->draw.movex) -
						(x / (f->draw.zoom * 1.1));
		f->draw.movey = (y / f->draw.zoom + f->draw.movey) -
						(y / (f->draw.zoom * 1.1));
		f->draw.zoom *= 1.1;
	}
	if (key == 7)
		f->draw.maxiterations -= 10;
	if (key == 6)
		f->draw.maxiterations += 10;
	threading(f);
	return (0);
}

int	mouse_move(int x, int y, t_f *f)
{
	if (x >= 0 && x <= W && y >= 0 && y <= H && f->draw.stop == 0)
	{
		f->draw.cim = 0.008 * (H / 2 - y);
		f->draw.cre = 0.004 * (W / 2 - x);
		threading(f);
	}
	return (0);
}
