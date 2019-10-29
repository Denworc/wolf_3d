/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:15:07 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:45:06 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	get_pixel(void *c, int x, int y, t_rgb *s)
{
	char	*tab;
	int		bpp;
	int		sl;
	int		e;
	int		z;

	tab = mlx_get_data_addr(c, &bpp, &sl, &e);
	z = y * sl + x * (bpp / 8);
	s->b = tab[z];
	s->g = tab[z + 1];
	s->r = tab[z + 2];
}

void	take_texture_(t_mlx *i, int x, int y, t_rgb *s)
{
	y = i->hei - y;
	i->st->cd = i->hei / (2.0 * y - i->hei - i->st->k_c * 2);
	i->st->w = (i->st->cd - i->st->dp) / (i->st->dw - i->st->dp);
	i->st->cfx = i->st->w * i->st->fx + (1.0 - i->st->w) * i->st->px;
	i->st->cfy = i->st->w * i->st->fy + (1.0 - i->st->w) * i->st->py;
	i->st->ftx = (int)(i->st->cfx * 512) % 512;
	i->st->fty = (int)(i->st->cfy * 512) % 512;
	y = i->hei - y;
	get_pixel(i->ceiling, i->wsx[0] + i->st->ftx * i->wmx[0] / 512,
				i->wsy[0] + i->st->fty * i->wmy[0] / 512, s);
	pixel_put(i, x, y, s);
}

void	take_texture_2(t_mlx *i, int x, int y, t_rgb *s)
{
	i->st->cd = i->hei / (2.0 * y - i->hei + i->st->k_c * 2);
	i->st->w = (i->st->cd - i->st->dp) / (i->st->dw - i->st->dp);
	i->st->cfx = i->st->w * i->st->fx + (1.0 - i->st->w) * i->st->px;
	i->st->cfy = i->st->w * i->st->fy + (1.0 - i->st->w) * i->st->py;
	i->st->ftx = (int)(i->st->cfx * 512) % 512;
	i->st->fty = (int)(i->st->cfy * 512) % 512;
	get_pixel(i->floor, i->wsx[2] + i->st->ftx * i->wmx[2] / 512,
				i->wsy[2] + i->st->fty * i->wmy[2] / 512, s);
	pixel_put(i, x, y, s);
}

void	take_texture(t_mlx *i, int x)
{
	int		y;
	t_rgb	s;

	if (i->re == 1)
		text_load(i, 512, 512);
	y = -1;
	add_color(&s, 0, 0, 0);
	while (++y < i->st->ds)
		take_texture_(i, x, y, &s);
	y = i->st->ds - 1;
	while (++y < i->st->de)
	{
		get_pixel(i->wall, i->wsx[1] + i->st->tx * i->wmx[1] / 512,
					i->wsy[1] + (y - i->st->ds) * i->wmy[1] / i->st->lh, &s);
		pixel_put(i, x, y, &s);
	}
	y = i->st->de - 1;
	add_color(&s, 175, 175, 175);
	while (++y < i->hei)
		take_texture_2(i, x, y, &s);
}

int		raycasting(t_mlx *i)
{
	int		x;
	t_rgb	col;

	if (i->img != NULL)
		mlx_destroy_image(i->mlx, i->img);
	i->img = mlx_new_image(i->mlx, i->wid, i->hei);
	i->tab = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->e);
	x = -1;
	while (++x < i->wid)
	{
		ft_ray(i, x);
		take_color(i, &col);
		if (i->c_mode == 0)
			put_color(i, &col, x);
		else
			take_texture(i, x);
	}
	get_frame(i);
	move_check(i);
	minimap(i);
	if (i->start == 0)
		start_menu(i, 1, 1);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
	return (0);
}
