/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:28:47 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 21:35:27 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	init_img2(t_f *f)
{
	int	bpp;
	int	sizeline;
	int	endian;

	f->draw.image = mlx_new_image(f->win.mlx_ptr, 1000, 1200);
	f->draw.data = mlx_get_data_addr(f->draw.image, &bpp, &sizeline, &endian);
	f->draw.bpp = bpp;
	f->draw.sizeline = sizeline;
	f->draw.endian = endian;
}

void	barns_key2(int key, t_f *f)
{
	if (key == 126 && f->up_down < 120)
	{
		f->up_down += 1;
		f->lef_rig += 1;
	}
	if (key == 125 && f->up_down > 10)
	{
		f->up_down -= 1;
		f->lef_rig -= 1;
	}
	if (key == 124 && f->mirror < 3)
		f->mirror += 0.1;
	if (key == 123 && f->mirror > -3)
		f->mirror -= 0.1;
	if (key == 4)
		start(f);
	wtrite_key2(key, f);
}

void	barnsley_start(t_f *f)
{
	f->draw.maxiterations = 100000;
	f->up_down = 120;
	f->lef_rig = 120;
	f->mirror = 1;
	f->real = 0;
	f->imag = 0;
	f->color = 0x00FF00;
}
