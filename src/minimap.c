/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:10:09 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:14:14 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	check_dist(t_mlx *i)
{
	if (i->st->side == 0)
		i->st->pwd = (i->st->mx - i->st->rpx + (1 - i->st->stx) / 2) /
			i->st->rdx;
	else
		i->st->pwd = (i->st->my - i->st->rpy + (1 - i->st->sty) / 2) /
			i->st->rdy;
	i->st->lh = i->hei / i->st->pwd;
	i->st->ds = -(i->st->lh) / 2 + i->hei / 2 - i->st->k_c;
	i->st->de = i->st->lh / 2 + i->hei / 2 - i->st->k_c;
	if (i->st->de >= i->hei)
		i->st->de = i->hei - 1;
	wall_text(i);
	floor_text(i);
}

void	draw_rec(t_mlx *t, int y, int x, t_rgb *col)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			pixel_put(t, x + i, y + j, col);
	}
}

void	draw_ex(t_mlx *i)
{
	t_rgb	col;
	int		x;
	int		y;

	x = -1;
	add_color(&col, 255, 150, 35);
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if ((i->nm == 1) && (x == 9) && (y == 9))
				draw_rec(i, x * 5, 1100 + y * 5, &col);
			else if ((i->nm == 2) && (x == 1) && (y == 9))
				draw_rec(i, x * 5, 1100 + y * 5, &col);
			else if ((i->nm == 3) && (x > 8) && (x < 11) && (y > 8) && (y < 11))
				draw_rec(i, x * 5, 1100 + y * 5, &col);
			else if ((i->nm == 4) && (x > 0) && (x < 7) && (y > 14) && (y < 19))
				draw_rec(i, x * 5, 1100 + y * 5, &col);
	}
}

void	minimap(t_mlx *i)
{
	t_rgb	col;
	int		x;
	int		y;

	x = -1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			if (i->st->map[x][y] == 1)
			{
				add_color(&col, 255, 255, 255);
				draw_rec(i, x * 5, 1100 + y * 5, &col);
			}
			else
			{
				add_color(&col, 0, 0, 0);
				draw_rec(i, x * 5, 1100 + y * 5, &col);
			}
	}
	draw_ex(i);
	add_color(&col, 255, 0, 0);
	draw_rec(i, floor(i->st->px) * 5, 1100 + floor(i->st->py) * 5, &col);
}

int		start_menu(t_mlx *i, int w, int h)
{
	if (i->img != NULL)
		mlx_destroy_image(i->mlx, i->img);
	i->img = mlx_xpm_file_to_image(i->mlx, "./include/textures/1.XPM", &w, &h);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
	return (0);
}
