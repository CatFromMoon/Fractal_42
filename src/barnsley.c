/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:35:00 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 21:35:03 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	barns_draw2(t_f *f, float rng)
{
	rng = ((float)rand()) / RAND_MAX;
	if (rng < 0.01f)
	{
		f->real = 0;
		f->imag = 0.16f * f->y;
	}
	else if (rng < 0.86f)
	{
		f->real = 0.85f * f->x + 0.04f * f->y;
		f->imag = -0.04f * f->x + 0.85f * f->y + 1.6f;
	}
	else if (rng < 0.93f)
	{
		f->real = 0.2f * f->x + -0.26f * f->y;
		f->imag = 0.23f * f->x + 0.22f * f->y + 1.6f;
	}
	else
	{
		f->real = -0.15f * f->x + 0.28f * f->y;
		f->imag = 0.26f * f->x + 0.24f * f->y + 0.44f;
	}
}

void	put_pixel_in_img1(t_f *f, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < 1000 && y < 1200)
		*(int *)&f->draw.data[(x * f->draw.bpp >> 3) +
					(y * f->draw.sizeline)] = color;
}

void	barns_draw(t_f *f)
{
	float	rng;

	f->i = 0;
	init_img2(f);
	while (f->i++ < f->draw.maxiterations)
	{
		barns_draw2(f, rng);
		put_pixel_in_img1(f, f->mirror * f->real * f->lef_rig + 500,
							1200 - f->imag * f->up_down, f->color);
		f->x = f->real;
		f->y = f->imag;
	}
	mlx_put_image_to_window(f->win.mlx_ptr, f->win.win_ptr,
									f->draw.image, 0, 0);
	mlx_destroy_image(f->win.mlx_ptr, f->draw.image);
}

int		barns_key(int key, t_f *f)
{
	mlx_clear_window(f->win.mlx_ptr, f->win.win_ptr);
	if (key == 78)
		f->draw.maxiterations -= 20000;
	if (key == 69)
		f->draw.maxiterations += 20000;
	barns_key2(key, f);
	if (key == 53)
		exit(1);
	barns_draw(f);
	return (0);
}

void	barnsley(t_f *f)
{
	f->win.mlx_ptr = mlx_init();
	f->win.win_ptr = mlx_new_window(f->win.mlx_ptr, 1000, 1200, "fractal");
	f->draw.maxiterations = 100000;
	barnsley_start(f);
	barns_draw(f);
	mlx_hook(f->win.win_ptr, 17, 0, mouse_close, f);
	mlx_hook(f->win.win_ptr, 2, 0, barns_key, f);
	mlx_loop(f->win.mlx_ptr);
}
