/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:06:39 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:47:32 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	ft_ray(t_mlx *i, int x)
{
	i->st->cx = 2 * x / (double)i->wid - 1;
	i->st->rpx = i->st->px;
	i->st->rpy = i->st->py;
	i->st->rdx = i->st->dx + i->st->plx * i->st->cx;
	i->st->rdy = i->st->dy + i->st->ply * i->st->cx;
	i->st->mx = (int)i->st->rpx;
	i->st->my = (int)i->st->rpy;
	i->st->ddx = sqrt(1 + (i->st->rdy * i->st->rdy) /
						(i->st->rdx * i->st->rdx));
	i->st->ddy = sqrt(1 + (i->st->rdx * i->st->rdx) /
						(i->st->rdy * i->st->rdy));
	check_step(i);
	dda_algoritm(i);
	check_dist(i);
}

void	check_step(t_mlx *i)
{
	if (i->st->rdx < 0)
	{
		i->st->stx = -1;
		i->st->sdx = (i->st->rpx - i->st->mx) * i->st->ddx;
	}
	else
	{
		i->st->stx = 1;
		i->st->sdx = (i->st->mx + 1.0 - i->st->rpx) * i->st->ddx;
	}
	if (i->st->rdy < 0)
	{
		i->st->sty = -1;
		i->st->sdy = (i->st->rpy - i->st->my) * i->st->ddy;
	}
	else
	{
		i->st->sty = 1;
		i->st->sdy = (i->st->my + 1.0 - i->st->rpy) * i->st->ddy;
	}
}

void	dda_algoritm(t_mlx *i)
{
	i->st->hit = 0;
	while (i->st->hit == 0)
	{
		if (i->st->sdx < i->st->sdy)
		{
			i->st->sdx += i->st->ddx;
			i->st->mx += i->st->stx;
			i->st->side = 0;
		}
		else
		{
			i->st->sdy += i->st->ddy;
			i->st->my += i->st->sty;
			i->st->side = 1;
		}
		if (i->st->map[i->st->mx][i->st->my] == 1)
			i->st->hit = 1;
	}
}

void	wall_text(t_mlx *i)
{
	if (i->st->side == 0)
		i->st->wx = i->st->rpy + i->st->pwd * i->st->rdy;
	else
		i->st->wx = i->st->rpx + i->st->pwd * i->st->rdx;
	i->st->wx -= floor((i->st->wx));
	i->st->tx = (int)(i->st->wx * (double)(512));
	if (i->st->side == 0 && i->st->rdx > 0)
		i->st->tx = 512 - i->st->tx - 1;
	if (i->st->side == 1 && i->st->rdy < 0)
		i->st->tx = 512 - i->st->tx - 1;
}

void	floor_text(t_mlx *i)
{
	if (i->st->side == 0 && i->st->rdx > 0)
	{
		i->st->fx = i->st->mx;
		i->st->fy = i->st->my + i->st->wx;
	}
	else if (i->st->side == 0 && i->st->rdx < 0)
	{
		i->st->fx = i->st->mx + 1.0;
		i->st->fy = i->st->my + i->st->wx;
	}
	else if (i->st->side == 1 && i->st->rdy > 0)
	{
		i->st->fx = i->st->mx + i->st->wx;
		i->st->fy = i->st->my;
	}
	else
	{
		i->st->fx = i->st->mx + i->st->wx;
		i->st->fy = i->st->my + 1.0;
	}
	i->st->dw = i->st->pwd;
	i->st->dp = 0.0;
	if (i->st->de < 0)
		i->st->de = 800;
}
