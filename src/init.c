/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:21:55 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/26 10:46:42 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	text_load(t_mlx *i, int w, int h)
{
	if (i->c_mode == 1)
		text_load1(i, w, h);
	else if (i->c_mode == 2)
		text_load2(i, w, h);
	else if (i->c_mode == 3)
		text_load3(i, w, h);
	else if (i->c_mode == 4)
		text_load4(i, w, h);
	else if (i->c_mode == 5)
		text_load5(i, w, h);
	if (i->c_mode != 0)
		i->re = 0;
}

void	init_var(t_mlx *i)
{
	i->wid = 1200;
	i->hei = 800;
	i->st->wall = 0;
	i->st->k_up = 0;
	i->st->k_down = 0;
	i->st->k_left = 0;
	i->st->k_right = 0;
	i->st->dx = -1;
	i->st->dy = 0;
	i->st->plx = 0;
	i->st->ply = 0.60;
	i->st->t = 0;
	i->st->ot = 0;
	i->img = NULL;
	i->st->px = 18.5;
	i->st->py = 1.5;
	i->st->k_run = 0;
	i->st->k_c = 0;
	i->c_mode = 0;
	i->start = 0;
	i->nm = 1;
}

void	my_init(t_mlx *i)
{
	int		j;

	j = -1;
	i->st = (t_c *)ft_memalloc(sizeof(t_c));
	init_var(i);
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, i->wid, i->hei, "W O L F 3 D");
	i->st->map = (int **)ft_memalloc(sizeof(int *) * 20);
	i->st->map1 = (int **)ft_memalloc(sizeof(int *) * 20);
	i->st->map2 = (int **)ft_memalloc(sizeof(int *) * 20);
	i->st->map3 = (int **)ft_memalloc(sizeof(int *) * 20);
	while (++j < 20)
		i->st->map[j] = (int *)ft_memalloc(sizeof(int) * 20);
	j = -1;
	while (++j < 20)
		i->st->map1[j] = (int *)ft_memalloc(sizeof(int) * 20);
	j = -1;
	while (++j < 20)
		i->st->map2[j] = (int *)ft_memalloc(sizeof(int) * 20);
	j = -1;
	while (++j < 20)
		i->st->map3[j] = (int *)ft_memalloc(sizeof(int) * 20);
	make_map(i);
}

void	turn_check(t_mlx *i, int dir)
{
	double	td;
	double	tpl;
	int		j;

	j = 1;
	td = i->st->dx;
	tpl = i->st->plx;
	if (dir == 1)
		j = -1;
	i->st->dx = i->st->dx * cos(j * i->st->rs) - i->st->dy * sin(j * i->st->rs);
	i->st->dy = td * sin(j * i->st->rs) + i->st->dy * cos(j * i->st->rs);
	i->st->plx = i->st->plx * cos(j * i->st->rs) -
		i->st->ply * sin(j * i->st->rs);
	i->st->ply = tpl * sin(j * i->st->rs) + i->st->ply * cos(j * i->st->rs);
}

void	move_check(t_mlx *i)
{
	if (i->st->k_left)
		turn_check(i, 0);
	if (i->st->k_right)
		turn_check(i, 1);
	if (i->st->k_up)
	{
		if (!(i->st->map[(int)(i->st->px + i->st->dx * 0.5)]
				[(int)(i->st->py + i->st->dy * 0.2)]))
			i->st->px += i->st->dx * i->st->ms;
		if (!(i->st->map[(int)(i->st->px + i->st->dx * 0.2)]
				[(int)(i->st->py + i->st->dy * 0.5)]))
			i->st->py += i->st->dy * i->st->ms;
	}
	if (i->st->k_down)
	{
		if (!(i->st->map[(int)(i->st->px - i->st->dx * 0.5)]
				[(int)(i->st->py - i->st->dy * 0.2)]))
			i->st->px -= i->st->dx * i->st->ms;
		if (!(i->st->map[(int)(i->st->px - i->st->dx * 0.2)]
				[(int)(i->st->py - i->st->dy * 0.5)]))
			i->st->py -= i->st->dy * i->st->ms;
	}
}
