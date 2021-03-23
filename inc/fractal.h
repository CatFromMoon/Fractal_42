/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:51:18 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/05 19:47:02 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define H 720
# define W 1440

# include "../libft/libft.h"
# include "mlx.h"
# include "stdlib.h"
# include "pthread.h"
# include "math.h"

typedef	struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef	struct	s_draw_map
{
	int			maxiterations;
	double		cre;
	double		cim;
	double		zoom;
	double		movex;
	double		movey;
	int			*image;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			y;
	int			x;
	int			stop;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
}				t_draw_map;

typedef	struct	s_menu
{
	int			m_menu;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_menu;

typedef struct	s_f
{
	t_draw_map	draw;
	t_window	win;
	t_menu		menu;
	int			thread_id;
	double		y;
	double		x;
	int			fractal;
	double		real;
	double		imag;
	int			up_down;
	int			lef_rig;
	double		mirror;
	int			color;
	int			i;
	int			barns;
}				t_f;

void			start(t_f *f);
void			barns_key2(int key, t_f *f);
void			init_img2(t_f *f);
void			init_img(t_f *f);
void			draw(t_f *f);
void			*draw_fr(void *data);
int				mouse_close(int key, t_f *f);
int				mouse_release(int key, int x, int y, t_f *f);
int				mouse_move(int x, int y, t_f *f);
int				wtrite_key(int key, t_f *f);
void			put_pixel_in_img(t_f *f, int x, int y, int color);
void			threading(t_f *f);
int				menu_key(int key, t_f *f);
void			menu(t_f *f, int key);
void			color(t_f *f, int key);
void			barnsley_start(t_f *f);
void			wtrite_key2(int key, t_f *f);
void			barns_draw(t_f *f);

void			mandelbrot(t_f *f);
void			julia(t_f *f);
void			ship(t_f *f);
void			barnsley(t_f *f);
void			dich(t_f *f);
void			ship2(t_f *f);
void			mandelbrot2(t_f *f);
void			mandelbrotsin(t_f *f);

#endif
