/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:47:30 by mchudik           #+#    #+#             */
/*   Updated: 2019/04/16 20:25:25 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

int		menu_key(int key, t_f *f)
{
	if (key == 48)
	{
		f->menu.m_menu = 1;
		mlx_destroy_window(f->menu.mlx_ptr, f->menu.win_ptr);
	}
	return (0);
}

void	julia_menu(t_f *f)
{
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			100, 0xFF4500, "'H' for return on the start projection");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			120, 0xFF4500, "'TAB' for close menu");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 0,
		160, 0xFF4500, "Only for Julia set:");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
		180, 0xFF4500, "'Spase' for pause");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
		200, 0xFF4500, "'S' for start");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 0,
		240, 0xFF4500, "Only for Barnsley set:");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
		260, 0xFF4500, "arrows up/down for size");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
		280, 0xFF4500, "arrows left/right for change the angle");
}

void	colors(t_f *f)
{
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr,
		0, 320, 0xFF4500, "Colors:");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		340, 0x00FF00, "'0' = green");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		360, 0xFF0000, "'1' = red");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		380, 0x0000FF, "'2' = blue");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		400, 0xC0C0C0, "'3' = silver");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		420, 0xFF8C00, "'4' = darkorange");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		440, 0xD2691E, "'5' = chocolate");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		460, 0xFFFFFF, "'6' = white");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		480, 0x800080, "'7' = purple");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		500, 0xFFFF00, "'8' = yellow");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 80,
		520, 0x00FFFF, "'9' = aqua");
	mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
		80, 0xFF4500, "'0-9' for another color");
}

void	menu(t_f *f, int key)
{
	f->barns == 1 ? barns_draw(f) : threading(f);
	if (f->menu.m_menu == 1)
	{
		key = 1;
		f->menu.m_menu = 2;
		f->menu.mlx_ptr = mlx_init();
		f->menu.win_ptr = mlx_new_window(f->menu.mlx_ptr, 800, 800, "MENU");
		mlx_hook(f->menu.win_ptr, 2, 0, menu_key, f);
		mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 0,
			0, 0xFF4500, "Use:");
		mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			0, 0xFF4500, "arrows for move fractol");
		mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			20, 0xFF4500, "'+/-' for iterations +/- 100");
		mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			40, 0xFF4500, "mouse wheel left/right for iterations +/- 10");
		mlx_string_put(f->menu.mlx_ptr, f->menu.win_ptr, 50,
			60, 0xFF4500, "mouse wheel up/down for zoom");
		julia_menu(f);
		colors(f);
		mlx_loop(f->menu.mlx_ptr);
	}
}
