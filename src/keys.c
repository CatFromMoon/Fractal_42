/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:07:14 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/04 20:09:09 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	wtrite_key2(int key, t_f *f)
{
	if (key == 48 && f->menu.m_menu == 1)
		menu(f, key);
	if (key == 48 && f->menu.m_menu == 2)
		menu_key(key, f);
	if (key == 4)
		start(f);
	color(f, key);
}

int		wtrite_key(int key, t_f *f)
{
	mlx_clear_window(f->win.mlx_ptr, f->win.win_ptr);
	if (key == 49 && f->draw.stop == 0)
		f->draw.stop = 1;
	if (key == 1 && f->draw.stop == 1)
		f->draw.stop = 0;
	if (key == 126)
		f->draw.movey += ((double)H / (100 * f->draw.zoom));
	if (key == 123)
		f->draw.movex += ((double)W / (100 * f->draw.zoom));
	if (key == 125)
		f->draw.movey -= ((double)H / (100 * f->draw.zoom));
	if (key == 124)
		f->draw.movex -= ((double)W / (100 * f->draw.zoom));
	if (key == 78)
		f->draw.maxiterations -= 100;
	if (key == 69)
		f->draw.maxiterations += 100;
	wtrite_key2(key, f);
	if (key == 53)
		exit(1);
	threading(f);
	return (0);
}

void	color(t_f *f, int key)
{
	if (key == 18)
		f->color = 0xFF0000;
	if (key == 19)
		f->color = 0x0000FF;
	if (key == 20)
		f->color = 0xC0C0C0;
	if (key == 21)
		f->color = 0xFF8C00;
	if (key == 23)
		f->color = 0xD2691E;
	if (key == 22)
		f->color = 0xFFFFFF;
	if (key == 26)
		f->color = 0x800080;
	if (key == 28)
		f->color = 0xFFFF00;
	if (key == 25)
		f->color = 0x00FFFF;
	if (key == 29)
		f->color = 0x00FF00;
}
