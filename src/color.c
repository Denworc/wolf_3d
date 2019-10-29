/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 09:49:36 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:14:52 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	pixel_put(t_mlx *i, int x, int y, t_rgb *c)
{
	int		z;

	z = y * i->sl + x * (i->bpp / 8);
	if (x < i->wid && x > 0 && y < i->hei && y > 0)
	{
		i->tab[z] = c->b;
		i->tab[z + 1] = c->g;
		i->tab[z + 2] = c->r;
	}
}

void	add_color(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

void	put_color(t_mlx *i, t_rgb *c, int x)
{
	int		y;
	t_rgb	s;

	y = 0;
	add_color(&s, 0, 0, 0);
	while (y < i->st->ds)
	{
		pixel_put(i, x, y, &s);
		y++;
	}
	y = i->st->ds;
	while (y < i->st->de)
	{
		pixel_put(i, x, y, c);
		y++;
	}
	y = i->st->de;
	add_color(&s, 175, 175, 175);
	while (y < i->hei)
	{
		pixel_put(i, x, y, &s);
		y++;
	}
}

void	get_frame(t_mlx *i)
{
	struct timeval	time;

	i->st->ot = i->st->t;
	gettimeofday(&time, NULL);
	i->st->t = time.tv_sec * 1000 + time.tv_usec / 1000;
	i->st->fr = i->st->t - i->st->ot;
	i->st->rs = i->st->fr * 0.002;
	if (i->st->k_run == 1)
		i->st->ms = i->st->fr * 0.0025;
	if (i->st->k_run == 0)
		i->st->ms = i->st->fr * 0.001;
}

void	take_color(t_mlx *i, t_rgb *c)
{
	if (i->st->side == 0)
	{
		if (i->st->stx == -1)
			add_color(c, 128, 0, 255);
		else
			add_color(c, 0, 102, 204);
	}
	else if (i->st->side == 1 && i->st->hit == 1)
	{
		if (i->st->sty == -1)
			add_color(c, 204, 204, 0);
		else
			add_color(c, 0, 204, 153);
	}
}
