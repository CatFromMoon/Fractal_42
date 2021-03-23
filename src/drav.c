/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drav.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:44:25 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 21:00:14 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	draw(t_f *f)
{
	f->menu.m_menu = 1;
	if (f->fractal == 4)
	{
		f->barns = 1;
		barnsley(f);
	}
	else
	{
		f->win.mlx_ptr = mlx_init();
		f->win.win_ptr = mlx_new_window(f->win.mlx_ptr, W, H, "fractol");
		init_img(f);
		start(f);
		threading(f);
		mlx_hook(f->win.win_ptr, 2, 0, wtrite_key, f);
		mlx_hook(f->win.win_ptr, 17, 0, mouse_close, f);
		mlx_hook(f->win.win_ptr, 4, 0, mouse_release, f);
		mlx_hook(f->win.win_ptr, 6, 0, mouse_move, f);
		mlx_loop(f->win.mlx_ptr);
	}
}

void	check_frac(t_f *f)
{
	if (f->fractal == 1)
		julia(f);
	if (f->fractal == 2)
		mandelbrot(f);
	if (f->fractal == 3)
		ship(f);
	if (f->fractal == 5)
		dich(f);
	if (f->fractal == 6)
		ship2(f);
	if (f->fractal == 7)
		mandelbrot2(f);
	if (f->fractal == 8)
		mandelbrotsin(f);
}

void	*draw_fr(void *data)
{
	t_f	*f;

	f = (t_f*)data;
	f->y = H / 8 * f->thread_id;
	while (f->y < H / 8 * (f->thread_id + 1))
	{
		f->x = 0;
		while (f->x < W)
		{
			check_frac(f);
			f->x++;
		}
		f->y++;
	}
	return (data);
}

void	init_img(t_f *f)
{
	int	bpp;
	int	sizeline;
	int	endian;

	f->draw.image = mlx_new_image(f->win.mlx_ptr, W, H);
	f->draw.data = mlx_get_data_addr(f->draw.image, &bpp, &sizeline, &endian);
	f->draw.bpp = bpp;
	f->draw.sizeline = sizeline;
	f->draw.endian = endian;
}

void	put_pixel_in_img(t_f *f, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
		*(int *)&f->draw.data[(x * f->draw.bpp >> 3) +
							(y * f->draw.sizeline)] = color;
}
