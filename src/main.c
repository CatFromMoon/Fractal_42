/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:54:09 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 20:01:36 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	threading(t_f *f)
{
	pthread_t	thr[8];
	t_f			mass[8];

	f->thread_id = 0;
	while (f->thread_id < 8)
	{
		ft_memcpy((void *)&mass[f->thread_id], (void *)f, sizeof(t_f));
		mass[f->thread_id].y = f->thread_id * 8;
		pthread_create(&thr[f->thread_id], NULL, draw_fr, &mass[f->thread_id]);
		f->thread_id++;
	}
	f->thread_id = 0;
	while (f->thread_id < 8)
	{
		pthread_join(thr[f->thread_id], NULL);
		f->thread_id++;
	}
	mlx_put_image_to_window(f->win.mlx_ptr, f->win.win_ptr,
							f->draw.image, 0, 0);
}

void	start(t_f *f)
{
	f->draw.maxiterations = 240;
	f->draw.zoom = 400;
	f->draw.movex = -1.8;
	f->draw.movey = -0.9;
	f->draw.cim = 0.27015;
	f->draw.cre = -0.7;
	f->color = 1;
	f->draw.stop = 0;
	f->barns = 0;
}

void	draw_errror(void)
{
	ft_putstr("Enter the fractal from the list\n");
	ft_putstr("1 Julia\n");
	ft_putstr("2 Mandelbrot\n");
	ft_putstr("3 Mandelbrot2\n");
	ft_putstr("4 MandelbrotSin\n");
	ft_putstr("5 Ship\n");
	ft_putstr("6 Ship2\n");
	ft_putstr("7 Dich\n");
	ft_putstr("8 Barnsley\n");
}

void	wht_draw(t_f *f, char *arg)
{
	if (ft_strcmp(arg, "Julia") == 0)
		f->fractal = 1;
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		f->fractal = 2;
	if (ft_strcmp(arg, "Ship") == 0)
		f->fractal = 3;
	if (ft_strcmp(arg, "Barnsley") == 0)
		f->fractal = 4;
	if (ft_strcmp(arg, "Dich") == 0)
		f->fractal = 5;
	if (ft_strcmp(arg, "Ship2") == 0)
		f->fractal = 6;
	if (ft_strcmp(arg, "Mandelbrot2") == 0)
		f->fractal = 7;
	if (ft_strcmp(arg, "MandelbrotSin") == 0)
		f->fractal = 8;
}

int		main(int argc, char *argv[])
{
	t_f			*f;

	f = (t_f*)malloc(sizeof(t_f));
	if (argc == 2)
	{
		wht_draw(f, argv[1]);
		f->fractal == 0 ? draw_errror() : draw(f);
	}
	else
		draw_errror();
	return (0);
}
